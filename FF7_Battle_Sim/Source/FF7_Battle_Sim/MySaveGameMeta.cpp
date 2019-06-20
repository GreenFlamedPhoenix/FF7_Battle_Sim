// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGameMeta.h"
#include "Kismet/GameplayStatics.h"

void UMySaveGameMeta::SaveGame(FString SlotToSave, FString inCharacterName, int32 inCharacterLevel, FString inArea, int32 inGil, int32 inDaysOne, int32 inDaysTwo, int32 inDaysThree, int32 inDaysFour, int32 inHoursOne, int32 inHoursTwo, int32 inMinutesOne, int32 inMinutesTwo, int32 inSecondsOne, int32 inSecondsTwo)
{
	UMySaveGameMeta* SaveGameInstance = Cast<UMySaveGameMeta>(UGameplayStatics::CreateSaveGameObject(UMySaveGameMeta::StaticClass()));
	SaveGameInstance->SavedCharacterName = inCharacterName;
	SaveGameInstance->SavedCharacterLevel = inCharacterLevel;
	SaveGameInstance->SavedArea = inArea;
	SaveGameInstance->SavedGil = inGil;
	SaveGameInstance->SavedDaysPlayedOne = inDaysOne;
	SaveGameInstance->SavedDaysPlayedTwo = inDaysTwo;
	SaveGameInstance->SavedDaysPlayedThree = inDaysThree;
	SaveGameInstance->SavedDaysPlayedFour = inDaysFour;
	SaveGameInstance->SavedHoursPlayedOne = inHoursOne;
	SaveGameInstance->SavedHoursPlayedTwo = inHoursTwo;
	SaveGameInstance->SavedMinutesPlayedOne = inMinutesOne;
	SaveGameInstance->SavedMinutesPlayedTwo = inMinutesTwo;
	SaveGameInstance->SavedSecondsPlayedOne = inSecondsOne;
	SaveGameInstance->SavedSecondsPlayedTwo = inSecondsTwo;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotToSave, 0);
}

void UMySaveGameMeta::LoadGame(FString SlotToLoad)
{
	UMySaveGameMeta* LoadGameInstance = Cast<UMySaveGameMeta>(UGameplayStatics::CreateSaveGameObject(UMySaveGameMeta::StaticClass()));
	LoadGameInstance = Cast<UMySaveGameMeta>(UGameplayStatics::LoadGameFromSlot(SlotToLoad, 0));
	LoadedCharacterName = LoadGameInstance->SavedCharacterName;
	LoadedCharacterLevel = LoadGameInstance->SavedCharacterLevel;
	LoadedArea = LoadGameInstance->SavedArea;
	LoadedGil = LoadGameInstance->SavedGil;
	LoadedDaysPlayedOne = LoadGameInstance->SavedDaysPlayedOne;
	LoadedDaysPlayedTwo = LoadGameInstance->SavedDaysPlayedTwo;
	LoadedDaysPlayedThree = LoadGameInstance->SavedDaysPlayedThree;
	LoadedDaysPlayedFour = LoadGameInstance->SavedDaysPlayedFour;
	LoadedHoursPlayedOne = LoadGameInstance->SavedHoursPlayedOne;
	LoadedHoursPlayedTwo = LoadGameInstance->SavedHoursPlayedTwo;
	LoadedMinutesPlayedOne = LoadGameInstance->SavedMinutesPlayedOne;
	LoadedMinutesPlayedTwo = LoadGameInstance->SavedMinutesPlayedTwo;
	LoadedSecondsPlayedOne = LoadGameInstance->SavedSecondsPlayedOne;
	LoadedSecondsPlayedTwo = LoadGameInstance->SavedSecondsPlayedTwo;
}
