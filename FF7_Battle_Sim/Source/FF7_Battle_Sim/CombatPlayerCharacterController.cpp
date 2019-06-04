// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"
#include "EnemyInfoWidget.h"
#include "ActionMenuWidget.h"


void ACombatPlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CombatGameMode != nullptr)
	{
		CombatGameMode->SetCombatPlayerController(this);
	}
	TriggerCountUpTimer();

	this->SetInputMode(FInputModeGameAndUI());
	this->bShowMouseCursor = true;
}

void ACombatPlayerCharacterController::SetEnemyBaseReference(AEnemyBase* EnemyBase)
{
	EnemyBaseReference = EnemyBase;
}

void ACombatPlayerCharacterController::SetEnemyInfoWidget(UEnemyInfoWidget* Widget)
{
	EnemyInfoWidget = Widget;
}

void ACombatPlayerCharacterController::SetActionMenuWidget(UActionMenuWidget* Widget)
{
	ActionMenuWidget = Widget;
}

void ACombatPlayerCharacterController::BeginAttack()
{

}

void ACombatPlayerCharacterController::TriggerCountUpTimer()
{
	GetWorld()->GetTimerManager().SetTimer(ActionCountTimer, this, &ACombatPlayerCharacterController::CountUpActionTimer, .10f, true, 0.f);
}

void ACombatPlayerCharacterController::CountUpActionTimer()
{
	if (CurrentActionTimer < MaxActionTimer)
	{
		CurrentActionTimer += .5f;
		//UE_LOG(LogTemp, Warning, TEXT("Current action timer at %f"), CurrentActionTimer);
	}
	else
	{
		bReadyForAction = true;
		ActionMenuWidget->SetWidgetVisibility(true);
		GetWorldTimerManager().PauseTimer(ActionCountTimer);
		ATB_Ready.Broadcast();
	}
}

void ACombatPlayerCharacterController::ResetActionTimer()
{
	CurrentActionTimer = 0.f;
	GetWorldTimerManager().UnPauseTimer(ActionCountTimer);
}