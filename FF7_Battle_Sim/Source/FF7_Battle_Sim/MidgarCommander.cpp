// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarCommander.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"

void AMidgarCommander::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::StartCursorHover(TouchComponent);

	bCurrentlyOverEnemy = true;
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

	bCurrentlyOverEnemy = false;
}

void AMidgarCommander::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

}