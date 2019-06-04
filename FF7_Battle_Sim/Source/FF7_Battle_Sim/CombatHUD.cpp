// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatHUD.h"

void ACombatHUD::BeginPlay()
{
	Super::BeginPlay();

	if (CombatStatusWidgetClass){CreateCombatStatusWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with CombatStatusWidgetClass"));}

	if (EnemyInfoWidgetClass){CreateEnemyInfoWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with EnemyInfoWidgetClass"));}

	if (ActionMenuWidgetClass){CreateActionMenuWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with ActionMenuWidgetClass"));}
}

void ACombatHUD::DrawHUD()
{
	Super::DrawHUD();
}

void ACombatHUD::CreateCombatStatusWidget()
{
	CombatStatusWidget = CreateWidget<UCombatStatusWidget>(GetWorld(), CombatStatusWidgetClass);
	CombatStatusWidget->AddToViewport(0);
}

void ACombatHUD::CreateEnemyInfoWidget()
{
	EnemyInfoWidget = CreateWidget<UEnemyInfoWidget>(GetWorld(), EnemyInfoWidgetClass);
	EnemyInfoWidget->AddToViewport(0);
}

void ACombatHUD::CreateActionMenuWidget()
{
	ActionMenuWidget = CreateWidget<UActionMenuWidget>(GetWorld(), ActionMenuWidgetClass);
	ActionMenuWidget->AddToViewport(1);
}