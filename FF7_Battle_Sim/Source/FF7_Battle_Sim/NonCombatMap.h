// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "NonCombatMap.generated.h"
class APlayerCharacter;
class UCombatTrackingComponent;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ANonCombatMap : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ANonCombatMap();
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCombatMap;

	UPROPERTY()
	APlayerCharacter* ControlledCharacter;

	UPROPERTY()
	UCombatTrackingComponent* PlayersCombatComponent;
};
