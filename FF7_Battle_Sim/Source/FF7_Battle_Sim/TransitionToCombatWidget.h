// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TransitionToCombatWidget.generated.h"
class AWorldMenuHUD;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UTransitionToCombatWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWorldMenuHUD* WorldMenuHUD;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inHUD);
};
