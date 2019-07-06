// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarCommander.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"
#include "ATB_Component.h"
#include "ActionMenuWidget.h"

AMidgarCommander::AMidgarCommander()
{
	// Create his ATB component and set up his ready event.
	ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB Component"));
	ATB_Component->ATB_FullEvent.AddDynamic(this, &AMidgarCommander::ATB_Full);

	// Base stats for the Midgar Commander.
	EnemyLevel = 4;
	EnemyCurrentHP = 200;
	EnemyMaxHP = 200;
	EnemyCurrentMP = 25;
	EnemyMaxMP = 25;
	EnemyStrength = 8;
	EnemyDexterity = 6;
	EnemyVitality = 18;
	EnemyLuck = 0;
	EnemyExpWorth = 18;
}

void AMidgarCommander::BeginPlay()
{
	Super::BeginPlay();

	// Check in with the Combat Game Mode and let it know your Exp worth.
	if (CombatGameMode){CombatGameMode->SetupEnemyAttributes(1, EnemyExpWorth);}
	else{UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!"));}

	// Determine how full your ATB bar is at the start of combat.
	if (ATB_Component){ATB_Component->DetermineATB_InitialFill(false);ATB_Component->CalculateATB_FillSpeed(EnemyDexterity, 1);}
	else{UE_LOG(LogTemp, Error, TEXT("No ATB Component found!"));}
}

void AMidgarCommander::StartCursorHover(UPrimitiveComponent* TouchComponent)
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

void AMidgarCommander::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);
}

void AMidgarCommander::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

	//TODO See about moving this to the base class.
	if (ActionMenuWidget->bAttemptingAttack == true)
	{
		// Get the incoming damage from the ActionMenuWidget.
		float IncomingDamage = ActionMenuWidget->CalculateDamageDealt();

		// Calculate your damage reduction.
		float DamageReduction = (float(EnemyVitality * 5) / 1700);

		// Calculate the final damage you will actually take.
		int32 DamageTaken = FMath::FloorToInt(IncomingDamage - (IncomingDamage * DamageReduction));
		EnemyCurrentHP -= DamageTaken;

		// Broadcast the damage taken to create the widget to display damage taken as text.
		DamageTakenNumberEvent.Broadcast(DamageTaken);

		if (EnemyCurrentHP > 0)
		{
			// If the enemy is still not dead broadcast for the damage animation and reset the EnemyInfoWidget.
			OnDamageEvent.Broadcast();
			ResetEnemyInfoStats();
		}
		else
		{
			// If the enemy is dead, broadcast for the death animation, update the CombatGameMode and remove the EnemyInfoWidget.
			OnDeathEvent.Broadcast();
			CombatGameMode->SetupEnemyAttributes(-1, 0);
			EnemysEnemyInfoWidget->SetWidgetVisibility(false);
		}

		// Reset the players ATB bar and reset our attacking boolean.
		EnemiesCombatCharacter->ATB_Component->ResetATB();
		ActionMenuWidget->bAttemptingAttack = false;
	}
}

void AMidgarCommander::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}

void AMidgarCommander::ATB_Full()
{
	bReadyForAction = true;
}
