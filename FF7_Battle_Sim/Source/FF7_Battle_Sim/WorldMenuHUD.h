// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WorldMenuHUD.generated.h"
class UWorldMenuMainWidget;
class USaveMenuWidget;
class APlayerCharacterController;
class UMainGameInstance;

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
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	APlayerCharacterController* PlayerCharacterController;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WorldMainMenuClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> SaveMenuClass;

	UPROPERTY()
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UPROPERTY()
	USaveMenuWidget* SaveMenuWidget;

	UFUNCTION()
	void ToggleMainMenuWidget();

	UFUNCTION()
	void OpenSaveMenu();
};
