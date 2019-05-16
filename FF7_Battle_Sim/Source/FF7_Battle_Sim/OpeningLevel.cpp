// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningLevel.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"

AOpeningLevel::AOpeningLevel()
{
	
}

void AOpeningLevel::BeginPlay()
{
	Super::BeginPlay();

	bCombatMap = true;

	GameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameInstance from level!")); return;}

	GameInstance->SetMapCombatState(bCombatMap);
}