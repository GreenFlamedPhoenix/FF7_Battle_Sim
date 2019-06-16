// Fill out your copyright notice in the Description page of Project Settings.


#include "MidgarCommander.h"
#include "CombatPlayerCharacterController.h"
#include "EnemyInfoWidget.h"
#include "CombatGameMode.h"
#include "CombatPlayerCharacter.h"
#include "ATB_Component.h"

AMidgarCommander::AMidgarCommander()
{
	ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB Component"));
	ATB_Component->ATB_Full.AddDynamic(this, &AMidgarCommander::ReadyForAction);
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
	EnemysEnemyInfoWidget->SetEnemyCurrentHP(CurrentHP);
	EnemysEnemyInfoWidget->SetEnemyMaxHP(MaxHP);
	EnemysEnemyInfoWidget->SetEnemyCurrentMP(CurrentMP);
	EnemysEnemyInfoWidget->SetEnemyMaxMP(MaxMP);
}

void AMidgarCommander::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	Super::EndCursorHover(TouchComponent);


}

void AMidgarCommander::ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey)
{
	Super::ActorBeingTargetted(TouchComponent, inKey);

	CurrentHP -= 1000;

	if (CurrentHP <= 0)
	{
		OnDeathEvent.Broadcast();
		CombatGameMode->SetupEnemyAttributes(-1, 0);
		EnemysEnemyInfoWidget->SetWidgetVisibility(false);
	}
}

void AMidgarCommander::ReadyForAction()
{
	UE_LOG(LogTemp, Warning, TEXT("Commander ready!"))
}
