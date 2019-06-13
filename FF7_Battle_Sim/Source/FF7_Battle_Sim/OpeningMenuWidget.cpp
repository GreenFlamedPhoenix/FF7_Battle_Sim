// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningMenuWidget.h"
#include "OpeningMenuHUD.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Button.h"
#include "UObjectGlobals.h"

void UOpeningMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UOpeningMenuWidget::SetOpeningMenuHUD(AOpeningMenuHUD* inHUD)
{OpeningMenuHUD = inHUD;}