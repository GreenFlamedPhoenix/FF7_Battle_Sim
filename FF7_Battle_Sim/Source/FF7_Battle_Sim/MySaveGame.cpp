// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMySaveGame::UMySaveGame()
{

}

void UMySaveGame::SaveGame(FString inSlotName, FName inMapName, FTransform PlayerTransform, int32 inCharacterLevel, TMap<FString, int32> inMap, int32 inDaysOne, int32 inDaysTwo, int32 inDaysThree, int32 inDaysFour, int32 inHoursOne, int32 inHoursTwo, int32 inMinutesOne, int32 inMinutesTwo, int32 inSecondsOne, int32 inSecondsTwo)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance->SavedSlotName = inSlotName;
	SaveGameInstance->SavedMap = inMapName;
	SaveGameInstance->SavedPlayerTransform = PlayerTransform;
	SaveGameInstance->SavedCharacterLevel = inCharacterLevel;
	SaveGameInstance->SavedCharacterMap = inMap;
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
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, inSlotName, 0);
}

void UMySaveGame::LoadGame(FString inSlotName)
{
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(inSlotName, 0));
	LoadedMap = LoadGameInstance->SavedMap;
	LoadedPlayerTransform = LoadGameInstance->SavedPlayerTransform;
	LoadedCharacterMap = LoadGameInstance->SavedCharacterMap;
	LoadedCharacterLevel = LoadGameInstance->SavedCharacterLevel;
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