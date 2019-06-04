// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyInfoWidget.h"
#include <Kismet/GameplayStatics.h>
#include "CombatPlayerCharacterController.h"
#include "MainGameInstance.h"
#include "Image.h"
#include "TextBlock.h"

UEnemyInfoWidget::UEnemyInfoWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UEnemyInfoWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	CombatController->SetEnemyInfoWidget(this);
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	MainGameInstance->SetEnemyInfoWidget(this);
}

void UEnemyInfoWidget::SetWidgetVisibility(bool HoveringOverEnemy)
{
	if (HoveringOverEnemy == true){CanvasBackground->SetVisibility(ESlateVisibility::HitTestInvisible);}
	else{CanvasBackground->SetVisibility(ESlateVisibility::Hidden);}
}

void UEnemyInfoWidget::SetEnemyName(FString inEnemyName)
{
	 EnemyName->SetText(FText::FromString(inEnemyName));
}

void UEnemyInfoWidget::SetEnemyCurrentHP(int32 CurrentHP)
{
	EnemyCurrentHP->SetText(FText::FromString(FString::FromInt(CurrentHP)));
}

void UEnemyInfoWidget::SetEnemyMaxHP(int32 MaxHP)
{
	EnemyMaxHP->SetText(FText::FromString(FString::FromInt(MaxHP)));
}

void UEnemyInfoWidget::SetEnemyCurrentMP(int32 CurrentMP)
{
	EnemyCurrentMP->SetText(FText::FromString(FString::FromInt(CurrentMP)));
}

void UEnemyInfoWidget::SetEnemyMaxMP(int32 MaxMP)
{
	EnemyMaxMP->SetText(FText::FromString(FString::FromInt(MaxMP)));
}
