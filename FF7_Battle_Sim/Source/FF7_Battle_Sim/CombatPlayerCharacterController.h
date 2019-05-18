// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	FTimerHandle ActionCountTimer;

	void CountUpActionTimer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentActionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxActionTimer = 25;
	
};
