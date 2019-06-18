// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SaveMenuWidget.generated.h"
class AWorldMenuHUD;
class UButton;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API USaveMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY()
	AWorldMenuHUD* WorldMenuHUD;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton;

	UFUNCTION()
	void ExitSaveMenu();
};
