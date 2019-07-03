// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatItemMenu.generated.h"
class ACombatHUD;
class UTextBlock;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UCombatItemMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetCombatHUD(ACombatHUD* inHUD);

	UPROPERTY()
	ACombatHUD* CombatHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PotionQuantity;

	UFUNCTION()
	void UpdatePotionQuantity();
	
};
