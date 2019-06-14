// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarSoldier.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"
#include "ActionMenuWidget.h"
#include "ATB_Component.h"

AMidgarSoldier::AMidgarSoldier()
{
	ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB_Component"));
	ATB_Component->ATB_Full.AddDynamic(this, &AMidgarSoldier::ReadyToAttack);
}

void AMidgarSoldier::BeginPlay()
{
	Super::BeginPlay();

	if (CombatGameMode){CombatGameMode->SetCurrentEnemiesAlive(1);}
	else {UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!"));}
	if (ATB_Component) {ATB_Component->DetermineATB_InitialFill(false); ATB_Component->CalculateATB_FillSpeed(Dexterity, 1);}
	else {UE_LOG(LogTemp, Error, TEXT("No ATB Component found!"));}
	
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

		if (CurrentHP > 0)
		{
			OnDamageEvent.Broadcast();
			ResetEnemyInfoStats();
		}
		else
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

void AMidgarSoldier::ReadyToAttack()
{
	bReadyForAction = true;
	UE_LOG(LogTemp, Warning, TEXT("Ready!"))
}

void AMidgarSoldier::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(CurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}