// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatusWidget.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "TextBlock.h"
#include "Button.h"

void UPlayerStatusWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	ExitButton->OnClicked.AddDynamic(this, &UPlayerStatusWidget::CloseMenu);
}

void UPlayerStatusWidget::SetWorldMenuHUD(AWorldMenuHUD* inHUD)
{

}

void UPlayerStatusWidget::SetPlayerCharacter(APlayerCharacter* inCharacter)
{
	PlayerCharacter = inCharacter;
}

void UPlayerStatusWidget::UpdateStats()
{
	StrengthStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Strength"))));
	DexterityStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Dexterity"))));
	VitalityStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Vitality"))));
	MagicStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Magic"))));
	SpiritStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Spirit"))));
	LuckStat->SetText(FText::FromString(FString::FromInt(*PlayerCharacter->PC_StatMap.Find("Luck"))));
}

void UPlayerStatusWidget::CloseMenu()
{
	this->RemoveFromViewport();
}