// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WorldMenuHUD.generated.h"
class UWorldMenuMainWidget;
class APlayerCharacterController;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AWorldMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	APlayerCharacterController* PlayerCharacterController;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WorldMainMenuClass;

	UPROPERTY()
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UFUNCTION()
	void ToggleMainMenuWidget();
	
};
