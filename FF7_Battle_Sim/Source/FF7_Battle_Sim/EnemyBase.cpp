
#include "EnemyBase.h"
#include <Kismet/GameplayStatics.h>
#include <Components/CapsuleComponent.h>
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "MainGameInstance.h"
#include "ActionMenuWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
	CharacterCapsule = this->GetCapsuleComponent();
	CharacterCapsule->OnBeginCursorOver.AddDynamic(this, &AEnemyBase::StartCursorHover);
	CharacterCapsule->OnEndCursorOver.AddDynamic(this, &AEnemyBase::EndCursorHover);
	CharacterCapsule->OnClicked.AddDynamic(this, &AEnemyBase::ActorBeingTargetted);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();


	CombatCharacter = Cast<ACombatPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));


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
	if (EnemysEnemyInfoWidget){EnemysEnemyInfoWidget->SetWidgetVisibility(true);}
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