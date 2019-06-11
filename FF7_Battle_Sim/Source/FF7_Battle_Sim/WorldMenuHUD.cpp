// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuHUD.h"
#include "WorldMenuMainWidget.h"
#include "PlayerCharacterController.h"

void AWorldMenuHUD::BeginPlay()
{
	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
}

void AWorldMenuHUD::ToggleMainMenuWidget()
{
	if (WorldMainMenuWidget)
	{
		if (WorldMainMenuWidget->IsInViewport())
		{
			WorldMainMenuWidget->RemoveFromViewport();
			PlayerCharacterController->SetInputMode(FInputModeGameOnly());
			PlayerCharacterController->bShowMouseCursor = false;
		}
		else
		{
			WorldMainMenuWidget->AddToViewport();
			PlayerCharacterController->SetInputMode(FInputModeGameAndUI());
			PlayerCharacterController->bShowMouseCursor = true;
			PlayerCharacterController->SetIgnoreMoveInput(true);
		}
		
	}
	else
	{
		if (WorldMainMenuClass)
		{
			WorldMainMenuWidget = CreateWidget<UWorldMenuMainWidget>(GetWorld(), WorldMainMenuClass);
			WorldMainMenuWidget->AddToViewport();
			PlayerCharacterController->SetInputMode(FInputModeGameAndUI());
			PlayerCharacterController->bShowMouseCursor = true;
		}
	}
}