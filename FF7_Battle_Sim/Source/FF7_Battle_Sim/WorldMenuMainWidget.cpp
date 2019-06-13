// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuMainWidget.h"
#include "MasterWorldMap.h"
#include "PlayerCharacter.h"
#include "WorldMenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "TextBlock.h"
#include "Image.h"
#include "ProgressBar.h"
#include "Button.h"


void UWorldMenuMainWidget::NativeOnInitialized()
{
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	MainGameInstance->SetWorldMenuMainWidget(this);
	GetWorld()->GetTimerManager().SetTimer(SearchCharacterTimer, this, &UWorldMenuMainWidget::FindMyCharacter, 0.5f, true, 0.f);
	SaveButton->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::OpenSaveScreen);
}

void UWorldMenuMainWidget::SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD)
{
	WorldMenuHUD = inWorldMenuHUD;
}

void UWorldMenuMainWidget::FindMyCharacter()
{
	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter)
	{
		SetPlayerIcon();
		PlayerCharacter->SetWorldMainMenuWidget(this);
		GetWorld()->GetTimerManager().ClearTimer(SearchCharacterTimer);
	}
}

void UWorldMenuMainWidget::SetPlayerIcon()
{
	if (PlayerCharacter && PlayerCharacter->PlayerIcon)
	{
		PlayerIcon->SetBrushFromTexture(PlayerCharacter->PlayerIcon);
	}
}

void UWorldMenuMainWidget::SetLocationNameText(FString inLevelName)
{
	LocationNameText->SetText(FText::FromString(inLevelName));
}

void UWorldMenuMainWidget::SetCharacterOneStats(int32 inCurrentHP, int32 inMaxHP, int32 inCurrentMP, int32 inMaxMP)
{
	CurrentHP->SetText(FText::FromString(FString::FromInt(inCurrentHP)));
	MaxHP->SetText(FText::FromString(FString::FromInt(inMaxHP)));
	CurrentMP->SetText(FText::FromString(FString::FromInt(inCurrentMP)));
	MaxMP->SetText(FText::FromString(FString::FromInt(inMaxMP)));
	CharacterOneHP_ProgressBar->SetPercent(inCurrentHP / inMaxHP);
	CharacterOneMP_ProgressBar->SetPercent(inCurrentMP / inMaxMP);
}

void UWorldMenuMainWidget::SetSaveEnabled(bool inbAbleToSave)
{
	if (inbAbleToSave == true)
	{
		SaveButton->SetIsEnabled(true);
	}
	else
	{
		SaveButton->SetIsEnabled(false);
	}
}

void UWorldMenuMainWidget::OpenSaveScreen()
{
	WorldMenuHUD->OpenSaveMenu();
}

void UWorldMenuMainWidget::UpdatePlayedTime(int32 inDays, int32 inHours, int32 inMinutes, int32 inSeconds)
{
	DaysPlayed->SetText(FText::FromString(FString::FromInt(inDays)));
	HoursPlayed->SetText(FText::FromString(FString::FromInt(inHours)));
	MinutesPlayed->SetText(FText::FromString(FString::FromInt(inMinutes)));
	SecondsPlayed->SetText(FText::FromString(FString::FromInt(inSeconds)));
}