// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerCharacterController.generated.h"
class ACombatThemeMaps;
class ACombatGameMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	ACombatGameMode* CombatGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTimerHandle ActionCountTimer;

	void CountUpActionTimer();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentActionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxActionTimer = 25;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bReadyForAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemianingPhysBarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemainingM_BarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxBarrierDuration = 60.f;

	ACombatThemeMaps* CurrentMap;
};