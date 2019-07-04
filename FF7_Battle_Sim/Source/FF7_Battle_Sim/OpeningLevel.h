// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MasterWorldMap.h"
#include "OpeningLevel.generated.h"
class AMasterWorldMap;
class UMainGameInstance;
class AWorldMapMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AOpeningLevel : public AMasterWorldMap
{
	GENERATED_BODY()

public:
	AOpeningLevel();

	virtual void BeginPlay() override;

	virtual FString GetMapName() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString MapName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCombatMap;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	UMainGameInstance* MainGameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	AWorldMapMode* WorldMapMode;

	UPROPERTY()
	FTimerHandle StupidDumbTimer;

	UFUNCTION()
	void StupidDumbTimerFunction();
};
