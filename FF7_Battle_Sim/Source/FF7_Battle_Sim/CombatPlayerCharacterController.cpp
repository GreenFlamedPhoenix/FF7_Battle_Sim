// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "ActionMenuWidget.h"

void ACombatPlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	this->SetInputMode(FInputModeGameAndUI());
	this->bShowMouseCursor = true;

	GetWorld()->GetTimerManager().SetTimer(ActionCountTimer, this, &ACombatPlayerCharacterController::CountUpActionTimer, .10f, true, 0.f);
}

void ACombatPlayerCharacterController::SetEnemyBaseReference(AEnemyBase* EnemyBase)
{EnemyBaseReference = EnemyBase;}

void ACombatPlayerCharacterController::SetActionMenuWidget(UActionMenuWidget* Widget)
{ActionMenuWidget = Widget;}

void ACombatPlayerCharacterController::CountUpActionTimer()
{
	if (CurrentActionTimer < MaxActionTimer)
	{
		CurrentActionTimer += .5f;
	}
	else
	{
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

void ACombatPlayerCharacterController::BeginAttack()
{

}