// Fill out your copyright notice in the Description page of Project Settings.


#include "NonCombatMap.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"

ANonCombatMap::ANonCombatMap()
{
	
}

void ANonCombatMap::BeginPlay()
{
	Super::BeginPlay();

	bCombatMap = false;

	GameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameInstance from level!")); return;}
	
	GameInstance->SetMapCombatState(bCombatMap);
}