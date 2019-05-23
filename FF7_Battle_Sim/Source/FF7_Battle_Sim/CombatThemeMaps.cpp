// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatThemeMaps.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"

void ACombatThemeMaps::BeginPlay()
{
	Super::BeginPlay();

	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CombatGameMode == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameMode from level!")) return;}
}

void ACombatThemeMaps::SetPlayerController()
{
	//CombatPlayerController = Cast<ACombatPlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	//if (CombatPlayerController == nullptr) { UE_LOG(LogTemp, Error, TEXT("Null PlayerController from level!")) return; }
}