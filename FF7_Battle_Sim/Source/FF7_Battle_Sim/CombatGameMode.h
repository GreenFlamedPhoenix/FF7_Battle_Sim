// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CombatGameMode.generated.h"
class UMainGameInstance;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UFUNCTION()
	void SetCurrentEnemiesAlive(int32 AmountChange);

	UPROPERTY()
	int32 CurrentEnemies = 0;
};
