// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "OpeningLevel.generated.h"

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AOpeningLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	AOpeningLevel();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCombatLevel;
	
	
};
