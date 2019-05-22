// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatThemeMaps.h"
#include "CombatPlayerCharacterController.h"
#include "MainGameInstance.h"

void ACombatThemeMaps::BeginPlay()
{
	Super::BeginPlay();

	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	if (MainGameInstance == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameInstance from level!")) return;}
}

void ACombatThemeMaps::SetPlayerController()
{
	CombatPlayerController = Cast<ACombatPlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	if (CombatPlayerController == nullptr) { UE_LOG(LogTemp, Error, TEXT("Null PlayerController from level!")) return; }
}