// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMenuMainWidget.h"
#include "MasterWorldMap.h"
#include "PlayerCharacter.h"
#include "TextBlock.h"
#include "Image.h"
#include "Kismet/GameplayStatics.h"

void UWorldMenuMainWidget::NativeOnInitialized()
{
	//GetWorld()->GetTimerManager().SetTimer(SearchMapTimer, this, &UWorldMenuMainWidget::FindMyMap, 0.5f, true, 0.f);
	GetWorld()->GetTimerManager().SetTimer(SearchCharacterTimer, this, &UWorldMenuMainWidget::FindMyCharacter, 0.5f, true, 0.f);
}

void UWorldMenuMainWidget::FindMyCharacter()
{
	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter)
	{
		SetPlayerIcon();
		GetWorld()->GetTimerManager().ClearTimer(SearchCharacterTimer);
		UE_LOG(LogTemp, Warning, TEXT("Found the character"));
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