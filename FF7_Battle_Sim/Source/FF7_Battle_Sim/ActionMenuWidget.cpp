// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionMenuWidget.h"
#include "MainGameInstance.h"
#include "CombatPlayerCharacterController.h"
#include "Button.h"
#include "CanvasPanel.h"
#include <Kismet/GameplayStatics.h>

UActionMenuWidget::UActionMenuWidget(const FObjectInitializer& ObjectInitilizer) : Super(ObjectInitilizer)
{
	
}

void UActionMenuWidget::NativeOnInitialized()
{
	MainGameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	MainGameInstance->SetActionMenuWidget(this);
	PlayerController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	PlayerController->SetActionMenuWidget(this);

	AttackCommandButton->OnClicked.AddDynamic(this, &UActionMenuWidget::AttackButtonClicked);
}

void UActionMenuWidget::SetWidgetVisibility(bool ReadyForAction)
{
	if (ReadyForAction == true)
	{
		MenuCanvas->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		AttackCommandButton->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		MenuCanvas->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UActionMenuWidget::AttackButtonClicked()
{
	bAttemptingAttack = true;
	//PlayerController->CurrentActionTimer = 0.f;
	//PlayerController->bReadyForAction = false;
	//GetWorld()->GetTimerManager().UnPauseTimer(PlayerController->ActionCountTimer);
	SetWidgetVisibility(false);
}