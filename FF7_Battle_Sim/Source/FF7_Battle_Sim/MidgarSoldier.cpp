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
	// Create his ATB component and set up his ready event.
	//ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB_Component"));
	ATB_Component->ATB_FullEvent.AddDynamic(this, &AMidgarSoldier::EnemyATB_Full);

	// Midgar Soldier enemy stats.
	EnemyLevel = 2;
	EnemyCurrentHP = 120;
	EnemyMaxHP = 120;
	EnemyCurrentMP = 20;
	EnemyMaxMP = 20;
	EnemyStrength = 6;
	EnemyDexterity = 7;
	EnemyVitality = 10;
	EnemyLuck = 0;
	EnemyExpWorth = 14;
}

void AMidgarSoldier::BeginPlay()
{
	Super::BeginPlay();

	// Check in with the Combat Game Mode and let it know your Exp worth.
	if (CombatGameMode){CombatGameMode->SetupEnemyAttributes(1, EnemyExpWorth);}
	else {UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!"));}

	// Determine how full your ATB bar is at the start of combat.
	if (ATB_Component){ATB_Component->DetermineATB_InitialFill(false);ATB_Component->CalculateATB_FillSpeed(EnemyDexterity, 1);}
	else {UE_LOG(LogTemp, Error, TEXT("No ATB Component found!"));}
}

void AMidgarSoldier::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::StartCursorHover(TouchComponent);

	//When we hover over the commander update the Enemy Info Widget.
	//TODO Compress this into one function, instead of several for each stat. Probably don't need to update max stats.
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

void AMidgarSoldier::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);
}

void AMidgarSoldier::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

	if (ActionMenuWidget->bAttemptingAttack == true)
	{
		float IncomingDamage = ActionMenuWidget->CalculateDamageDealt();
		float DamageReduction = (float(EnemyVitality * 5) / 1700);

		int32 DamageTaken = FMath::FloorToInt(IncomingDamage - (IncomingDamage * DamageReduction));
		EnemyCurrentHP -= DamageTaken;

		DamageTakenNumberEvent.Broadcast(DamageTaken);

		if (EnemyCurrentHP > 0)
		{
			OnDamageEvent.Broadcast();
			ResetEnemyInfoStats();
		}
		else
		{
			OnDeathEvent.Broadcast();
			CombatGameMode->SetupEnemyAttributes(-1, 0);
			EnemysEnemyInfoWidget->SetWidgetVisibility(false);
		}

		EnemiesCombatCharacter->ATB_Component->ResetATB();
		ActionMenuWidget->bAttemptingAttack = false;
	}
}

void AMidgarSoldier::Attack()
{
	Super::Attack();

	ATB_Component->ResetATB();
}


void AMidgarSoldier::DrinkPotion()
{
	if (PotionsRemaining > 0)
	{
		EnemyCurrentHP += 50;
		if (EnemyCurrentHP > EnemyMaxHP)
		{
			EnemyCurrentHP = EnemyMaxHP;
		}
		PotionsRemaining -= 1;
	}
	ResetEnemyInfoStats();
	ATB_Component->ResetATB();
	bSoldierReadyForAction = false;
}

void AMidgarSoldier::EnemyATB_Full()
{
	bSoldierReadyForAction = true;
}

void AMidgarSoldier::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}