// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMySaveGame::UMySaveGame()
{

}

void UMySaveGame::SaveGame(FString inSlotName, int32 inDays, int32 inHours, int32 inMinutes, int32 inSeconds)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance->SavedSlotName = inSlotName;
	SaveGameInstance->SavedDaysPlayed = inDays;
	SaveGameInstance->SavedHoursPlayed = inHours;
	SaveGameInstance->SavedMinutesPlayed = inMinutes;
	SaveGameInstance->SavedSecondsPlayed = inSeconds;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, inSlotName, 0);
}

void UMySaveGame::LoadGame(FString inSlotName)
{
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(inSlotName, 0));
	LoadedDaysPlayed = LoadGameInstance->SavedDaysPlayed;
	LoadedHoursPlayed = LoadGameInstance->SavedHoursPlayed;
	LoadedMinutesPlayed = LoadGameInstance->SavedMinutesPlayed;
	LoadedSecondsPlayed = LoadGameInstance->SavedSecondsPlayed;
}