// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarSoldier.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"

void AMidgarSoldier::StartCursorHover(UPrimitiveComponent* TouchComponent)
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

void AMidgarSoldier::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);


}

void AMidgarSoldier::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

}