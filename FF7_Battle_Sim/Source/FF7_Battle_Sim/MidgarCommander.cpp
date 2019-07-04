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
	ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB Component"));
	ATB_Component->ATB_Full.AddDynamic(this, &AMidgarCommander::ReadyForAction);

	EnemyLevel = 4;
	EnemyCurrentHP = 200;
	EnemyMaxHP = 200;
	EnemyCurrentMP = 25;
	EnemyMaxMP = 25;
	EnemyStrength = 8;
	EnemyDexterity = 6;
	EnemyExpWorth = 18;
	EnemyVitality = 13;
}

void AMidgarCommander::BeginPlay()
{
	Super::BeginPlay();

	if (CombatGameMode){CombatGameMode->SetupEnemyAttributes(1, ExpWorth);}
	else{UE_LOG(LogTemp, Error, TEXT("No CombatGameMode!"));}
	if (ATB_Component){ATB_Component->DetermineATB_InitialFill(false);ATB_Component->CalculateATB_FillSpeed(Dexterity, 1);}
	else{UE_LOG(LogTemp, Error, TEXT("No ATB Component found!"));}
}

void AMidgarCommander::StartCursorHover(UPrimitiveComponent* TouchComponent)
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

void AMidgarCommander::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);


}

void AMidgarCommander::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
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

void AMidgarCommander::ReadyForAction()
{

}

void AMidgarCommander::ResetEnemyInfoStats()
{
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(EnemyCurrentHP);
	EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	EnemysEnemyInfoWidget->SetWidgetVisibility(true);
}