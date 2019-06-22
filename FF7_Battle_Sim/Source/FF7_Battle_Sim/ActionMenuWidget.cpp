// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionMenuWidget.h"
#include "MainGameInstance.h"
#include "CombatPlayerCharacterController.h"
#include "Button.h"
#include "CanvasPanel.h"
#include <Kismet/GameplayStatics.h>
#include "CombatHUD.h"
#include "CombatPlayerCharacter.h"

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

void UActionMenuWidget::SetCombatHUD(ACombatHUD* inHUD)
{
	CombatHUD = inHUD;
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
	SetWidgetVisibility(false);
}

float UActionMenuWidget::CalculateDamageDealt()
{
	if (CombatHUD)
	{
		if (CombatHUD->CombatPlayerCharacter)
		{
			if (CombatHUD->CombatPlayerCharacter->CPC_StatMap.Contains("Strength"))
			{
				float StrengthToUse = float(*CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("Strength"));
				float BaseDamage = (StrengthToUse / 4.5) * (StrengthToUse / .95);

				float WeakAttack = BaseDamage*.95;
				float StrongAttack = BaseDamage*1.05;

				return (FMath::RandRange(WeakAttack, StrongAttack));
			}
			else{UE_LOG(LogTemp, Warning, TEXT("Strength not found"))return 0.f;}	
		}
		else{UE_LOG(LogTemp, Warning, TEXT("No CPC"))return 0.f;}
	}
	else{UE_LOG(LogTemp, Warning, TEXT("No HUD"))return 0.f;}
}