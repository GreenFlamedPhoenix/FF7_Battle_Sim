// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuHUD.h"
#include "WorldMenuMainWidget.h"
#include "PlayerCharacterController.h"
#include "PlayerCharacter.h"

void AWorldMenuHUD::BeginPlay()
{
	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	if (WorldMainMenuClass){WorldMainMenuWidget = CreateWidget<UWorldMenuMainWidget>(GetWorld(), WorldMainMenuClass);}

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
}