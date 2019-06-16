// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CombatGameMode.generated.h"
class UMainGameInstance;
class ACombatPlayerCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCombatComplete);

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
	void SetupEnemyAttributes(int32 AmountChange, int32 inExp);

	UPROPERTY()
	int32 CurrentEnemies = 0;

	UPROPERTY()
	FTimerHandle CloseCombatTimer;

	UPROPERTY()
	int32 CombatCloseCounter = 6;

	UFUNCTION()
	void CountDownCombatCounter();

	UPROPERTY()
	ACombatPlayerCharacter* CombatPlayerCharacter;

	UFUNCTION()
	void SetCombatCharacter(ACombatPlayerCharacter* inCombatPlayerCharacter);

	UPROPERTY()
	int32 ExpToAward;
};
