// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarSoldier.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"
#include "ConstructorHelpers.h"
#include "ActionMenuWidget.h"

void AMidgarSoldier::BeginPlay()
{
	Super::BeginPlay();

	SetEnemyLevel();
	//CalculateActionSpeed();

	if (CombatGameMode){CombatGameMode->SetCurrentEnemiesAlive(1);}
	else { UE_LOG(LogTemp, Warning, TEXT("No CombatGameMode!")) }
}


void AMidgarSoldier::SetEnemyLevel()
{
	if (MyLevel == ""){MyLevel = FString::FromInt(FMath::RandRange(1, 5));}
}

void AMidgarSoldier::CalculateActionSpeed()
{
	MyActionSpeed = .25f + (0.05f * SpeedStat);
}

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
	EnemysEnemyInfoWidget->SetEnemyLevel(MyLevel);
}

void AMidgarSoldier::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);


}

void AMidgarSoldier::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

	if (ActionMenuWidget->bAttemptingAttack == true)
	{
		CurrentHP -= 75;

		OnDamageEvent.Broadcast();
		ResetEnemyInfoStats();

		if (CurrentHP <= 0)
		{
			OnDeathEvent.Broadcast();
			CombatGameMode->SetCurrentEnemiesAlive(-1);
			EnemysEnemyInfoWidget->SetWidgetVisibility(false);
		}

		CombatController->ResetActionTimer();
		ActionMenuWidget->bAttemptingAttack = false;
	}
}

void AMidgarSoldier::DrinkPotion()
{
	if (PotionsRemaining > 0)
	{
		CurrentHP += 50;
		if (CurrentHP > MaxHP)
		{
			CurrentHP = MaxHP;
		}
		PotionsRemaining -= 1;
	}
	ResetEnemyInfoStats();
}

void AMidgarSoldier::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(CurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}