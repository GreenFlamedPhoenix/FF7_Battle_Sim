// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarCommander.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"

void AMidgarCommander::BeginPlay()
{
	Super::BeginPlay();

	if (CombatGameMode)
	{
		CombatGameMode->SetCurrentEnemiesAlive(1);
	}
	else {UE_LOG(LogTemp, Warning, TEXT("No CombatGameMode!"))}
}

void AMidgarCommander::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::StartCursorHover(TouchComponent);

	FHitResult ActorHit;
	CombatController->GetHitResultUnderCursor(ECC_Pawn, true, ActorHit);
	HoveredActor = ActorHit.GetActor();
	EnemysEnemyInfoWidget->SetEnemyName(HoveredActor->GetName());
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(CurrentHP);
	EnemysEnemyInfoWidget->SetEnemyMaxHP(MaxHP);
	EnemysEnemyInfoWidget->SetEnemyCurrentMP(CurrentMP);
	EnemysEnemyInfoWidget->SetEnemyMaxMP(MaxMP);
}

void AMidgarCommander::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);


}

void AMidgarCommander::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

	CurrentHP -= 75;

	if (CurrentHP <= 0)
	{
		OnDeathEvent.Broadcast();
		CombatGameMode->SetCurrentEnemiesAlive(-1);
		EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	}
}