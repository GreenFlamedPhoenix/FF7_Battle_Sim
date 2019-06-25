// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuMainWidget.h"
#include "MasterWorldMap.h"
#include "PlayerCharacter.h"
#include "WorldMenuHUD.h"
#include "PlayerStatusWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "TextBlock.h"
#include "Image.h"
#include "ProgressBar.h"
#include "Button.h"
#include "CanvasPanel.h"
#include "Kismet/KismetSystemLibrary.h"


void UWorldMenuMainWidget::NativeOnInitialized()
{
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	MainGameInstance->SetWorldMenuMainWidget(this);
	GetWorld()->GetTimerManager().SetTimer(SearchCharacterTimer, this, &UWorldMenuMainWidget::FindMyCharacter, 0.5f, true, 0.f);
	SaveButton->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::OpenSaveScreen);
	StatusButton->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::OpenStatusMenu);
	QuitButton->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::OpenConfirmQuit);
	ConfirmQuit->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::ConfirmQuitGame);
	CancelQuit->OnClicked.AddDynamic(this, &UWorldMenuMainWidget::CancelQuitGame);
}

void UWorldMenuMainWidget::MenuOpened()
{
	SetPlayerOneExp();
	SetPlayerOneLevel();
	SetPlayerOneExpBar();
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

void UWorldMenuMainWidget::SetCharacterOneStats()
{
	CurrentHP->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("CurrentHP"))));
	MaxHP->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("MaxHP"))));
	CurrentMP->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("CurrentMP"))));
	MaxMP->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("MaxMP"))));

	SetHP_MP_Bars();
}

void UWorldMenuMainWidget::SetHP_MP_Bars()
{
	float StatCurrentHP = float(*PlayerCharacter->PC_StatMap.Find("CurrentHP"));
	float StatMaxHP = float(*PlayerCharacter->PC_StatMap.Find("MaxHP"));
	float StatCurrentMP = float(*PlayerCharacter->PC_StatMap.Find("CurrentMP"));
	float StatMaxMP = float(*PlayerCharacter->PC_StatMap.Find("MaxMP"));

	float HP_Percent = StatCurrentHP / StatMaxHP;
	float MP_Percentage = StatCurrentMP  / StatMaxMP;

	CharacterOneHP_ProgressBar->SetPercent(HP_Percent);
	CharacterOneMP_ProgressBar->SetPercent(MP_Percentage);
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

void UWorldMenuMainWidget::OpenStatusMenu()
{
	WorldMenuHUD->OpenStatusMenu();
}

void UWorldMenuMainWidget::UpdatePlayedTime(int32 inDaysOne, int32 inDaysTwo, int32 inDaysThree, int32 inDaysFour, int32 inHoursOne, int32 inHoursTwo, int32 inMinutesOne, int32 inMinutesTwo, int32 inSecondsOne, int32 inSecondsTwo)
{
	DaysPlayedOne->SetText(FText::FromString(FString::FromInt(inDaysOne)));
	DaysPlayedTwo->SetText(FText::FromString(FString::FromInt(inDaysTwo)));
	DaysPlayedThree->SetText(FText::FromString(FString::FromInt(inDaysThree)));
	DaysPlayedFour->SetText(FText::FromString(FString::FromInt(inDaysFour)));
	HoursPlayedOne->SetText(FText::FromString(FString::FromInt(inHoursOne)));
	HoursPlayedTwo->SetText(FText::FromString(FString::FromInt(inHoursTwo)));
	MinutesPlayedOne->SetText(FText::FromString(FString::FromInt(inMinutesOne)));
	MinutesPlayedTwo->SetText(FText::FromString(FString::FromInt(inMinutesTwo)));
	SecondsPlayedOne->SetText(FText::FromString(FString::FromInt(inSecondsOne)));
	SecondsPlayedTwo->SetText(FText::FromString(FString::FromInt(inSecondsTwo)));
}

void UWorldMenuMainWidget::SetPlayerOneExp()
{
	PlayerOneCurrentExp->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("CurrentExp"))));
	PlayerOneExpToLevel->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("ExpToLevel"))));
}

void UWorldMenuMainWidget::SetPlayerOneLevel()
{
	PlayerOneLevel->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Level"))));
}

void UWorldMenuMainWidget::SetPlayerOneExpBar()
{
	float CurrentExp = float(*PlayerCharacter->PC_StatMap.Find("CurrentExp"));
	float ExpToLevel = float(*PlayerCharacter->PC_StatMap.Find("ExpToLevel"));

	float FillPercent = CurrentExp / ExpToLevel;
	PlayerOneExpBar->SetPercent(FillPercent);
}

void UWorldMenuMainWidget::OpenConfirmQuit()
{
	ConfirmQuitCanvas->SetVisibility(ESlateVisibility::Visible);
	WorldMenuHUD->PlayerCharacterController->DisableInput(GetWorld()->GetFirstPlayerController());
}

void UWorldMenuMainWidget::ConfirmQuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, false);
}

void UWorldMenuMainWidget::CancelQuitGame()
{
	ConfirmQuitCanvas->SetVisibility(ESlateVisibility::Hidden);
	WorldMenuHUD->PlayerCharacterController->EnableInput(GetWorld()->GetFirstPlayerController());
}