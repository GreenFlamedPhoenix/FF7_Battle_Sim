// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatGameMode.h"
#include "MainGameInstance.h"
#include "CombatPlayerCharacter.h"

void ACombatGameMode::BeginPlay()
{
	Super::BeginPlay();

	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
}

void ACombatGameMode::SetCombatCharacter(ACombatPlayerCharacter* inCombatPlayerCharacter)
{
	CombatPlayerCharacter = inCombatPlayerCharacter;
}

void ACombatGameMode::SetCurrentEnemiesAlive(int32 AmountChange)
{
	CurrentEnemies = CurrentEnemies + AmountChange;
	if (CurrentEnemies == 0)
	{
		CombatPlayerCharacter->bCombatFinished = true;
		GetWorldTimerManager().SetTimer(CloseCombatTimer, this, &ACombatGameMode::CountDownCombatCounter, 1.f, true, 0.f);
	}
}

void ACombatGameMode::CountDownCombatCounter()
{
	if (CombatCloseCounter > 0)
	{
		CombatCloseCounter -= 1;
	}
	else
	{
		CombatPlayerCharacter->bCombatFinished = false;
		MainGameInstance->CompleteCombat(MainGameInstance->MapFName);
	}
}
