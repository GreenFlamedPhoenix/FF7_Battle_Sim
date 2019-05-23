// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "OpeningLevel.generated.h"
class UMainGameInstance;
class AWorldMapMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AOpeningLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	AOpeningLevel();
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCombatMap;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	UMainGameInstance* GameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	AWorldMapMode* WorldMapMode;
};
