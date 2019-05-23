// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CombatGameMode.generated.h"
class ACombatPlayerCharacterController;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetCombatPlayerController(ACombatPlayerCharacterController* PlayerController);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACombatPlayerCharacterController* CombatPlayerController;
};
