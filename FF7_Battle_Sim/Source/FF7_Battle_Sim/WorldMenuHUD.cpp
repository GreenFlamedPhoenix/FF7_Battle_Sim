// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuHUD.h"
#include "WorldMenuMainWidget.h"
#include "PlayerCharacterController.h"
#include "MainGameInstance.h"
#include "SaveMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void AWorldMenuHUD::BeginPlay()
{
	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (WorldMainMenuClass){WorldMainMenuWidget = CreateWidget<UWorldMenuMainWidget>(GetWorld(), WorldMainMenuClass);}
	if (WorldMainMenuWidget){WorldMainMenuWidget->SetWorldMenuHUD(this);}
	if (SaveMenuClass){SaveMenuWidget = CreateWidget<USaveMenuWidget>(GetWorld(), SaveMenuClass);}
	if (SaveMenuWidget){SaveMenuWidget->SetWorldMenuHUD(this);}
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
			WorldMainMenuWidget->SetCharacterOneStats(MainGameInstance->CharacterOneCurrentHP, MainGameInstance->CharacterOneMaxHP, MainGameInstance->CharacterOneCurrentMP, MainGameInstance->CharacterOneMaxMP);
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