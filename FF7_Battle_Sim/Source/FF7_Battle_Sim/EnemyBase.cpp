
#include "EnemyBase.h"
#include <Kismet/GameplayStatics.h>
#include <Components/CapsuleComponent.h>
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "MainGameInstance.h"
#include "ActionMenuWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"
#include "ATB_Component.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
	CharacterCapsule = this->GetCapsuleComponent();
	CharacterCapsule->OnBeginCursorOver.AddDynamic(this, &AEnemyBase::StartCursorHover);
	CharacterCapsule->OnEndCursorOver.AddDynamic(this, &AEnemyBase::EndCursorHover);
	CharacterCapsule->OnClicked.AddDynamic(this, &AEnemyBase::ActorBeingTargetted);
	Enemy_ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("My ATB Component"));
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();


	EnemiesCombatCharacter = Cast<ACombatPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));


	CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	CombatController->SetEnemyBaseReference(this);

	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	EnemysEnemyInfoWidget = MainGameInstance->EnemyInfoWidget;
	ActionMenuWidget = MainGameInstance->PlayerActionMenuWidget;


	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Function called when we hover over our enemy. Also called by children overriding this function, which hold most of the functionality.
void AEnemyBase::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	if (EnemysEnemyInfoWidget)
	{
		EnemysEnemyInfoWidget->SetWidgetVisibility(true);

		FHitResult ActorHit;
		CombatController->GetHitResultUnderCursor(ECC_Pawn, true, ActorHit);
		HoveredActor = ActorHit.GetActor();
		EnemysEnemyInfoWidget->SetEnemyName(HoveredActor->GetName());
		EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
		EnemysEnemyInfoWidget->SetEnemyMaxHP(EnemyMaxHP);
		EnemysEnemyInfoWidget->SetEnemyCurrentMP(EnemyCurrentMP);
		EnemysEnemyInfoWidget->SetEnemyMaxMP(EnemyMaxMP);
		EnemysEnemyInfoWidget->SetEnemyLevel(EnemyLevel);
	}
	else{UE_LOG(LogTemp,Error,TEXT("No EnemyInfoWidget found!"));return;}
}

// Function called when we finish hovering over our enemy. Also called by children overriding this function, which hold most of the functionality.
void AEnemyBase::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	if (EnemysEnemyInfoWidget){EnemysEnemyInfoWidget->SetWidgetVisibility(false);}
	else{UE_LOG(LogTemp,Error,TEXT("No EnemyInfoWidget found!"));return;}
}

// Function called when we click on our actor. Mainly to just test attacking for now. Also called by children overriding this function.
void AEnemyBase::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	//Functionality mostly handled by child classes.
}

void AEnemyBase::Attack()
{
	
	//Determine base damage to deal.
	float BaseDamageOutput = (EnemyStrength / 4.5) * (EnemyStrength / .95);
	float LowDamageOutput = BaseDamageOutput * .95;
	float HighDamageOutput = BaseDamageOutput * 1.05;
	float InitialFinalDamage = FMath::RandRange(LowDamageOutput, HighDamageOutput);
	float FinalDamageDealt;

	//UE_LOG(LogTemp, Warning, TEXT("EnemyStrength %i"), EnemyStrength)

	//Check for a critical hit.
	float CritPercentage = ((EnemyLuck * 2.75) + (EnemyStrength * 1.75) + (EnemyLevel / 1.05)) / 10;
	float ChanceRoll = FMath::RandRange(0.f, 100.f);
	if (ChanceRoll < CritPercentage)
	{FinalDamageDealt = InitialFinalDamage * 1.5;}
	else
	{FinalDamageDealt = InitialFinalDamage;}

	//UE_LOG(LogTemp, Warning, TEXT("Attacking for %f"), FinalDamageDealt)
	EnemiesCombatCharacter->PlayerTakeDamage(FinalDamageDealt);
}