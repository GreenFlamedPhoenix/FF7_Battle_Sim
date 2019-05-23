// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NonCombatMap.h"
#include "CombatThemeMaps.generated.h"
class ACombatGameMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatThemeMaps : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetPlayerController();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//ACombatPlayerCharacterController* CombatPlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACombatGameMode* CombatGameMode;
};