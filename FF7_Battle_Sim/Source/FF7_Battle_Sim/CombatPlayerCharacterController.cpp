// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacterController.h"

void ACombatPlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(ActionCountTimer, this, &ACombatPlayerCharacterController::CountUpActionTimer, .10f, true, 0.f);
}

void ACombatPlayerCharacterController::CountUpActionTimer()
{
	if (CurrentActionTimer < MaxActionTimer)
	{
		CurrentActionTimer += .5f;
		//UE_LOG(LogTemp, Warning, TEXT("Current action timer at %f"), CurrentActionTimer);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(ActionCountTimer);
	}
}