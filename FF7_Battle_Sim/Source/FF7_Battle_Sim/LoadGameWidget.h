// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadGameWidget.generated.h"
class AOpeningMenuHUD;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ULoadGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AOpeningMenuHUD* OpeningMenuHUD;

	UFUNCTION()
	void SetOpeningMenuHUD(AOpeningMenuHUD* inHUD);

	
};
