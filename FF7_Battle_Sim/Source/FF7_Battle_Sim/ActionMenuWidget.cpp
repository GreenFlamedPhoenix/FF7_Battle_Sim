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

				float FinalDamage = FMath::RandRange(WeakAttack, StrongAttack);

				if (DetermineCriticalHit() == true)
				{
					UE_LOG(LogTemp, Warning, TEXT("Critical Hit!"))
					return FinalDamage * 1.5;
				}
				else
				{
					return FinalDamage;
				}
			}
			else{UE_LOG(LogTemp, Warning, TEXT("Strength not found"))return 0.f;}	
		}
		else{UE_LOG(LogTemp, Warning, TEXT("No CPC"))return 0.f;}
	}
	else{UE_LOG(LogTemp, Warning, TEXT("No HUD"))return 0.f;}
}

bool UActionMenuWidget::DetermineCriticalHit()
{
	float MyLuck = float(*CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("Luck"));
	float MyStrength = float(*CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("Strength"));
	float MyLevel = float(*CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("Level"));

	float CritPercentage = ((MyLuck * 2.75) + (MyStrength * 1.75) + (MyLevel / 1.05)) / 10;
	float ChanceRoll = FMath::RandRange(0.f, 100.f);
	UE_LOG(LogTemp, Warning, TEXT("Critical Chance: %f"), CritPercentage)
	if (ChanceRoll < CritPercentage)
	{
		return true;
	}
	else
	{
		return false;
	}
}