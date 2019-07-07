// Fill out your copyright notice in the Description page of Project Settings.


#include "DevilDog.h"
#include "CombatGameMode.h"
#include "ATB_Component.h"
#include "ActionMenuWidget.h"
#include "EnemyInfoWidget.h"
#include "CombatPlayerCharacter.h"


ADevilDog::ADevilDog()
{
	// Base stats for the Midgar Commander.
	EnemyLevel = 6;
	EnemyCurrentHP = 200;
	EnemyMaxHP = 200;
	EnemyCurrentMP = 25;
	EnemyMaxMP = 25;
	EnemyStrength = 6;
	EnemyDexterity = 10;
	EnemyVitality = 10;
	EnemyLuck = 0;
	EnemyExpWorth = 25;
}

void ADevilDog::BeginPlay()
{
	Super::BeginPlay();

	// Check in with the Combat Game Mode and let it know your Exp worth.
	if (CombatGameMode) { CombatGameMode->SetupEnemyAttributes(1, EnemyExpWorth); }
	else { UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!")); }

	// Determine how full your ATB bar is at the start of combat.
	if (Enemy_ATB_Component) { Enemy_ATB_Component->DetermineATB_InitialFill(false); Enemy_ATB_Component->CalculateATB_FillSpeed(EnemyDexterity, 1); }
	else { UE_LOG(LogTemp, Error, TEXT("No ATB Component found!")); }
}

void ADevilDog::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::StartCursorHover(TouchComponent);

}

void ADevilDog::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);

}

void ADevilDog::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
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

void ADevilDog::Attack()
{
	Super::Attack();

	Enemy_ATB_Component->ResetATB();
}

void ADevilDog::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}