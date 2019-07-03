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

	EnemyLevel = 2;
	EnemyCurrentHP = 120;
	EnemyMaxHP = 120;
	EnemyCurrentMP = 20;
	EnemyMaxMP = 20;
	EnemyStrength = 6;
	EnemyDexterity = 7;
	EnemyExpWorth = 12;
	EnemyVitality = 10;
}

void AMidgarSoldier::BeginPlay()
{
	Super::BeginPlay();

	if (CombatGameMode){CombatGameMode->SetupEnemyAttributes(1, EnemyExpWorth);}
	else {UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!"));}
	if (ATB_Component) {ATB_Component->DetermineATB_InitialFill(false); ATB_Component->CalculateATB_FillSpeed(EnemyDexterity, 1);}
	else {UE_LOG(LogTemp, Error, TEXT("No ATB Component found!"));}
	
}

void AMidgarSoldier::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::StartCursorHover(TouchComponent);

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
		UE_LOG(LogTemp, Warning, TEXT("Damage Taken: %i"), DamageTaken);

		if (EnemyCurrentHP > 0)
		{
			OnDamageEvent.Broadcast(DamageTaken);
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
	bReadyForAction = false;
}

void AMidgarSoldier::ReadyToAttack()
{
	bReadyForAction = true;
}

void AMidgarSoldier::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}