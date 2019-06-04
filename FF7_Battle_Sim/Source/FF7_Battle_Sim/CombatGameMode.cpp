// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatGameMode.h"
#include "MainGameInstance.h"

void ACombatGameMode::BeginPlay()
{
	Super::BeginPlay();

	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
}

void ACombatGameMode::SetCurrentEnemiesAlive(int32 AmountChange)
{
	CurrentEnemies = CurrentEnemies + AmountChange;
	if (CurrentEnemies == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("All enemies killed! You won!"));
		MainGameInstance->CompleteCombat(MainGameInstance->MapFName);
	}
}