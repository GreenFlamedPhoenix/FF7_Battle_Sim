// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "ActionMenuWidget.h"

void ACombatPlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	this->SetInputMode(FInputModeGameAndUI());
	this->bShowMouseCursor = true;
}

void ACombatPlayerCharacterController::SetEnemyBaseReference(AEnemyBase* EnemyBase)
{EnemyBaseReference = EnemyBase;}

void ACombatPlayerCharacterController::SetActionMenuWidget(UActionMenuWidget* Widget)
{ActionMenuWidget = Widget;}