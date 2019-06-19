// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatusWidget.h"
#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TextBlock.h"
#include "Button.h"

void UPlayerStatusWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if(MainGameInstance) {MainGameInstance->SetPlayerStatusWidget(this);}

	ExitButton->OnClicked.AddDynamic(this, &UPlayerStatusWidget::CloseMenu);

	UpdateStats(MainGameInstance->GI_PlayerStrength, MainGameInstance->GI_PlayerDexterity, MainGameInstance->GI_PlayerVitality, MainGameInstance->GI_PlayerMagic, MainGameInstance->GI_PlayerSpirit, MainGameInstance->GI_PlayerLuck);
}

void UPlayerStatusWidget::SetWorldMenuHUD(AWorldMenuHUD* inHUD)
{

}

void UPlayerStatusWidget::UpdateStats(int32 inStrength, int32 inDexterity, int32 inVitality, int32 inMagic, int32 inSpirit, int32 inLuck)
{
	StrengthStat->SetText(FText::FromString(FString::FromInt(inStrength)));
	DexterityStat->SetText(FText::FromString(FString::FromInt(inDexterity)));
	VitalityStat->SetText(FText::FromString(FString::FromInt(inVitality)));
	MagicStat->SetText(FText::FromString(FString::FromInt(inMagic)));
	SpiritStat->SetText(FText::FromString(FString::FromInt(inSpirit)));
	LuckStat->SetText(FText::FromString(FString::FromInt(inLuck)));
}

void UPlayerStatusWidget::CloseMenu()
{
	this->RemoveFromViewport();
}