// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatThemeMaps.h"
#include "CombatPlayerCharacterController.h"

void ACombatThemeMaps::BeginPlay()
{
	Super::BeginPlay();

}

void ACombatThemeMaps::SetPlayerController()
{
	CombatPlayerController = Cast<ACombatPlayerCharacterController>(GetWorld()->GetFirstPlayerController());
}