// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGameMeta.generated.h"

/**
 *  
 */
UCLASS()
class FF7_BATTLE_SIM_API UMySaveGameMeta : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SaveGame(FString SlotToSave, FString inCharacterName, int32 inCharacterLevel, FString inArea, int32 inGil, int32 inDaysOne, int32 inDaysTwo, int32 inDaysThree, int32 inDaysFour, int32 inHoursOne, int32 inHoursTwo, int32 inMinutesOne, int32 inMinutesTwo, int32 inSecondsOne, int32 inSecondsTwo);

	UFUNCTION(BlueprintCallable)
	void LoadGame(FString SlotToLoad);

	//////////////////////////////
	//	Variables to save.
	//////////////////////////////
	UPROPERTY()
	FString SavedCharacterName;
	UPROPERTY()
	int32 SavedCharacterLevel;
	UPROPERTY()
	FString SavedArea;
	UPROPERTY()
	int32 SavedGil;
	UPROPERTY()
	int32 SavedDaysPlayedOne;
	UPROPERTY()
	int32 SavedDaysPlayedTwo;
	UPROPERTY()
	int32 SavedDaysPlayedThree;
	UPROPERTY()
	int32 SavedDaysPlayedFour;
	UPROPERTY()
	int32 SavedHoursPlayedOne;
	UPROPERTY()
	int32 SavedHoursPlayedTwo;
	UPROPERTY()
	int32 SavedMinutesPlayedOne;
	UPROPERTY()
	int32 SavedMinutesPlayedTwo;
	UPROPERTY()
	int32 SavedSecondsPlayedOne;
	UPROPERTY()
	int32 SavedSecondsPlayedTwo;

	//////////////////////////////
	//	Variables to load.
	//////////////////////////////
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString LoadedCharacterName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedCharacterLevel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString LoadedArea;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedGil;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedDaysPlayedOne;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedDaysPlayedTwo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedDaysPlayedThree;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedDaysPlayedFour;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedHoursPlayedOne;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedHoursPlayedTwo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedMinutesPlayedOne;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedMinutesPlayedTwo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedSecondsPlayedOne;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LoadedSecondsPlayedTwo;
};
