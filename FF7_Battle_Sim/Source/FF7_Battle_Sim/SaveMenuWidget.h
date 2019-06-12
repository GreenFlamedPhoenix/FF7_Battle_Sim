// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SaveMenuWidget.generated.h"
class AWorldMenuHUD;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API USaveMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AWorldMenuHUD* WorldMenuHUD;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD);
	
};
