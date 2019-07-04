// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningLevel.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "WorldMapMode.h"
#include "WorldMenuMainWidget.h"

AOpeningLevel::AOpeningLevel()
{
	
}

void AOpeningLevel::BeginPlay()
{
	Super::BeginPlay();

	bCombatMap = true;

	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	if (MainGameInstance == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameInstance from level!")); return;}

	MainGameInstance->SetMapCombatState(bCombatMap);

	WorldMapMode = Cast<AWorldMapMode>(UGameplayStatics::GetGameMode(GetWorld()));

	GetWorldTimerManager().SetTimer(StupidDumbTimer, this, &AOpeningLevel::StupidDumbTimerFunction, 1.f, true, 0.f);
}

FString AOpeningLevel::GetMapName()
{
	return MapName;
}

void AOpeningLevel::StupidDumbTimerFunction()
{
	if (WorldMainMenuWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found it."))
		WorldMainMenuWidget->SetLocationNameText(MapName);
	}
	else
	{
		return;
	}
}