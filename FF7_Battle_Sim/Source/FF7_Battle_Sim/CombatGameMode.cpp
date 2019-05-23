// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatGameMode.h"
#include "CombatPlayerCharacterController.h"

void ACombatGameMode::SetCombatPlayerController(ACombatPlayerCharacterController* PlayerController)
{
	CombatPlayerController = PlayerController;
}