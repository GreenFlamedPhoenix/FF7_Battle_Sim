// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WorldMenuHUD.generated.h"
class UWorldMenuMainWidget;
class USaveMenuWidget;
class APlayerCharacterController;
class UMainGameInstance;
class UPlayerStatusWidget;
class UTransitionToCombatWidget;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AWorldMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	APlayerCharacterController* PlayerCharacterController;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WorldMainMenuClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> SaveMenuClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> PlayerStatusClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> TranstitionToCombatClass;

	UPROPERTY()
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UPROPERTY()
	USaveMenuWidget* SaveMenuWidget;

	UPROPERTY()
	UPlayerStatusWidget* PlayerStatusWidget;

	UPROPERTY()
	UTransitionToCombatWidget* TransitionToCombatWidget;

	UFUNCTION()
	void ToggleMainMenuWidget();

	UFUNCTION()
	void OpenSaveMenu();

	UFUNCTION()
	void OpenStatusMenu();
};
