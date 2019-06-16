// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatHUD.h"
#include "CombatPlayerCharacter.h"
#include "ATB_Component.h"
#include "Kismet/GameplayStatics.h"

void ACombatHUD::BeginPlay()
{
	Super::BeginPlay();

	if (CombatStatusWidgetClass){CreateCombatStatusWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with CombatStatusWidgetClass"));}

	if (EnemyInfoWidgetClass){CreateEnemyInfoWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with EnemyInfoWidgetClass"));}

	if (ActionMenuWidgetClass){CreateActionMenuWidget();}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with ActionMenuWidgetClass"));}

	GetWorld()->GetTimerManager().SetTimer(ReferenceSearchTimer, this, &ACombatHUD::SearchForReferences, 0.1f, true, 0.f);
}

void ACombatHUD::DrawHUD()
{
	Super::DrawHUD();
}

void ACombatHUD::SetPlayerCharacter(ACombatPlayerCharacter* inCharacter)
{
	CombatPlayerCharacter = inCharacter;
}

void ACombatHUD::SetATB_Component(UATB_Component* inComponent)
{
	ATB_Component = inComponent;
}

void ACombatHUD::SearchForReferences()
{
	if (CombatPlayerCharacter && ATB_Component){bReferencesReady = true; GetWorld()->GetTimerManager().ClearTimer(ReferenceSearchTimer);}
}

void ACombatHUD::CreateCombatStatusWidget()
{
	CombatStatusWidget = CreateWidget<UCombatStatusWidget>(GetWorld(), CombatStatusWidgetClass);
	CombatStatusWidget->AddToViewport(0);
	CombatStatusWidget->SetHUD_Reference(this);
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