// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "OpeningMenuHUD.generated.h"
class ULoadGameWidget;
class UOpeningMenuWidget;
class UMainGameInstance;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AOpeningMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> LoadGameClass;

	UPROPERTY()
	ULoadGameWidget* LoadGameWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> OpeningMenuClass;

	UPROPERTY()
	UOpeningMenuWidget* OpeningMenuWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMainGameInstance* MainGameInstance;

	UFUNCTION()
	void OpenLoadMenu();
};
