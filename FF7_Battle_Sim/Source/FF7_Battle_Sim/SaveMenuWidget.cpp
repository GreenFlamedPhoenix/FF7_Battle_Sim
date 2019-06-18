// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveMenuWidget.h"
#include "WorldMenuHUD.h"
#include "Button.h"

void USaveMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BackButton->OnClicked.AddDynamic(this, &USaveMenuWidget::ExitSaveMenu);
}

void USaveMenuWidget::SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD)
{
	WorldMenuHUD = inWorldMenuHUD;
}

void USaveMenuWidget::ExitSaveMenu()
{
	this->RemoveFromViewport();
}