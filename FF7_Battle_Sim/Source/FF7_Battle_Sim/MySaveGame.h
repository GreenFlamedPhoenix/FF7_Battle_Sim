// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UMySaveGame();

	UFUNCTION(BlueprintCallable)
	void SaveGame(FString inSlotName, int32 inDays, int32 inHours, int32 inMinutes, int32 inSeconds);

	UFUNCTION(BlueprintCallable)
	void LoadGame(FString InSlotName);

	UPROPERTY()
	FString SavedSlotName;

	UPROPERTY()
	int32 SavedDaysPlayed;

	UPROPERTY()
	int32 SavedHoursPlayed;

	UPROPERTY()
	int32 SavedMinutesPlayed;

	UPROPERTY()
	int32 SavedSecondsPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedDaysPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedHoursPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedMinutesPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedSecondsPlayed;
	
};
