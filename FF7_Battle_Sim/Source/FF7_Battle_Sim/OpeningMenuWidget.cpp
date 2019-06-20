// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningMenuWidget.h"
#include "OpeningMenuHUD.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Button.h"
#include "UObjectGlobals.h"
#include "Kismet/KismetSystemLibrary.h"

void UOpeningMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	QuitButton->OnClicked.AddDynamic(this, &UOpeningMenuWidget::QuitButtonClicked);
	ContinueButton->OnClicked.AddDynamic(this, &UOpeningMenuWidget::ContinueButtonClicked);
}

void UOpeningMenuWidget::SetOpeningMenuHUD(AOpeningMenuHUD* inHUD)
{
	OpeningMenuHUD = inHUD;
}

void UOpeningMenuWidget::ContinueButtonClicked()
{
	OpeningMenuHUD->OpenLoadMenu();
}

void UOpeningMenuWidget::QuitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, false);
}
