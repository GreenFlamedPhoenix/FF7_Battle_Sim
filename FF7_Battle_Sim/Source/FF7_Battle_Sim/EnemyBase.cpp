// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include <Components/CapsuleComponent.h>
#include "CombatPlayerCharacterController.h"
#include <Kismet/GameplayStatics.h>
#include "EnemyInfoWidget.h"
#include <SlateWrapperTypes.h>
#include "MainGameInstance.h"
#include "ActionMenuWidget.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CharacterCapsule = this->GetCapsuleComponent();
	CharacterCapsule->OnBeginCursorOver.AddDynamic(this, &AEnemyBase::StartCursorHover);
	CharacterCapsule->OnEndCursorOver.AddDynamic(this, &AEnemyBase::EndCursorHover);
	CharacterCapsule->OnClicked.AddDynamic(this, &AEnemyBase::ActorBeingTargetted);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	CombatController->SetEnemyBaseReference(this);
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	EnemysEnemyInfoWidget = MainGameInstance->EnemyInfoWidget;
	ActionMenuWidget = MainGameInstance->PlayerActionMenuWidget;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	if (EnemysEnemyInfoWidget)
	{
		EnemysEnemyInfoWidget->SetWidgetVisibility(true);
	}
	else{UE_LOG(LogTemp,Error,TEXT("No EnemyInfoWidget found!"));return;}
}

void AEnemyBase::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	if (EnemysEnemyInfoWidget)
	{
		EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	}
	else{UE_LOG(LogTemp,Error,TEXT("No EnemyInfoWidget found!"));return;}
}

void AEnemyBase::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	if (ActionMenuWidget->bAttemptingAttack == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attacking!"));
		CombatController->ResetActionTimer();
	}
	else { UE_LOG(LogTemp, Warning, TEXT("Not attacking so I am doing nothing!")); return; }
}