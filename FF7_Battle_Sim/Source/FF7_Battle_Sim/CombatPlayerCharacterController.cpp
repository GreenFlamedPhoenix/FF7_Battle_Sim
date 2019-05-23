// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"


void ACombatPlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CombatGameMode != nullptr)
	{
		CombatGameMode->SetCombatPlayerController(this);
	}
	TriggerCountUpTimer();

	this->SetInputMode(FInputModeUIOnly());
	this->bShowMouseCursor = true;
}

void ACombatPlayerCharacterController::TriggerCountUpTimer()
{
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
		bReadyForAction = true;
		GetWorldTimerManager().PauseTimer(ActionCountTimer);
	}
}