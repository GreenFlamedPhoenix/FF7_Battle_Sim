// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterWorldMap.h"
#include "WorldMenuMainWidget.h"

void AMasterWorldMap::BeginPlay()
{
	Super::BeginPlay();

}

void AMasterWorldMap::SetWorldMenuMainWidget(UWorldMenuMainWidget* inWorldMainMenuWidget)
{
	WorldMainMenuWidget = inWorldMainMenuWidget;
}

FString AMasterWorldMap::GetMapName()
{
	return "";
}