// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningMenuHUD.h"
#include "LoadGameWidget.h"
#include "OpeningMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void AOpeningMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (LoadGameClass){LoadGameWidget = CreateWidget<ULoadGameWidget>(GetWorld(), LoadGameClass);}
	if (OpeningMenuClass){OpeningMenuWidget = CreateWidget<UOpeningMenuWidget>(GetWorld(), OpeningMenuClass);}
	if (LoadGameWidget){LoadGameWidget->SetOpeningMenuHUD(this);}
	if (OpeningMenuWidget){OpeningMenuWidget->SetOpeningMenuHUD(this); OpeningMenuWidget->AddToViewport();}

	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

void AOpeningMenuHUD::OpenLoadMenu()
{
	LoadGameWidget->AddToViewport();
}