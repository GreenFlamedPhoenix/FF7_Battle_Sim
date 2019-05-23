// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMapMode.h"
#include "PlayerCharacterController.h"

void AWorldMapMode::SetWorldPlayerController(APlayerCharacterController* inWorldPlayerController)
{
	WorldPlayerController = inWorldPlayerController;
}