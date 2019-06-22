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

	if (CombatGameMode){CombatGameMode->SetupEnemyAttributes(1, ExpWorth);}
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
		float IncomingDamage = ActionMenuWidget->CalculateDamageDealt();
		float DamageReduction = (float(Vitality * 5) / 1700);

		int32 DamageTaken = FMath::FloorToInt(IncomingDamage - (IncomingDamage * DamageReduction));
		CurrentHP -= DamageTaken;
		UE_LOG(LogTemp, Warning, TEXT("Damage Taken: %i"), DamageTaken);

		if (CurrentHP > 0)
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
		CombatCharacter->ATB_Component->ResetATB();

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
	ATB_Component->ResetATB();
}

void AMidgarSoldier::ReadyToAttack()
{
	bReadyForAction = true;
}

void AMidgarSoldier::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(CurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}