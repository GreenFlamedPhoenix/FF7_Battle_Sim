// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuHUD.h"
#include "WorldMenuMainWidget.h"
#include "PlayerCharacterController.h"
#include "MainGameInstance.h"
#include "SaveMenuWidget.h"
#include "PlayerStatusWidget.h"
#include "Kismet/GameplayStatics.h"

void AWorldMenuHUD::BeginPlay()
{
	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (WorldMainMenuClass){WorldMainMenuWidget = CreateWidget<UWorldMenuMainWidget>(GetWorld(), WorldMainMenuClass);}
	if (WorldMainMenuWidget){WorldMainMenuWidget->SetWorldMenuHUD(this);}

	if (SaveMenuClass){SaveMenuWidget = CreateWidget<USaveMenuWidget>(GetWorld(), SaveMenuClass);}
	if (SaveMenuWidget){SaveMenuWidget->SetWorldMenuHUD(this);}

	if (PlayerStatusClass) {PlayerStatusWidget = CreateWidget<UPlayerStatusWidget>(GetWorld(), PlayerStatusClass);}
	if (PlayerStatusWidget) {PlayerStatusWidget->SetWorldMenuHUD(this);}
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
			PlayerCharacterController->SetIgnoreMoveInput(false);
		}
		else
		{
			WorldMainMenuWidget->AddToViewport();
			PlayerCharacterController->SetInputMode(FInputModeGameAndUI());
			PlayerCharacterController->bShowMouseCursor = true;
			PlayerCharacterController->SetIgnoreMoveInput(true);
			WorldMainMenuWidget->SetCharacterOneStats();
			WorldMainMenuWidget->MenuOpened();
		}

	}
}

void AWorldMenuHUD::OpenSaveMenu()
{
	if (SaveMenuWidget)
	{
		SaveMenuWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Issues with save menu"))
	}
}

void AWorldMenuHUD::OpenStatusMenu()
{
	if (PlayerStatusWidget)
	{
		PlayerStatusWidget->AddToViewport();
	}
}
