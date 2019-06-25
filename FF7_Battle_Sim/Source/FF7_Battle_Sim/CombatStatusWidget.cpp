// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusWidget.h"
#include <Kismet/GameplayStatics.h>
#include "CombatPlayerCharacter.h"
#include "ATB_Component.h"
#include "CombatHUD.h"
#include "TextBlock.h"
#include "ProgressBar.h"

UCombatStatusWidget::UCombatStatusWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UCombatStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UCombatStatusWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (CombatHUD->ATB_Component)
	{
		ATB_TimeBarFill();
		ATB_TimeBarTint();
	}
	if (CombatHUD->CombatPlayerCharacter)
	{
		ManageHP();
		ManageMP();
	}
}

void UCombatStatusWidget::SetHUD_Reference(ACombatHUD* inHUD)
{
	CombatHUD = inHUD;
}

void UCombatStatusWidget::ManageHP()
{	
	int32 CurrentHP = *CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("CurrentHP");
	int32 MaxHP = *CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("MaxHP");

	float FCurrentHP = CurrentHP;
	float FMaxHP = MaxHP;

	float HP_Percentage = FCurrentHP / FMaxHP;

	CharacterCurrentHP->SetText(FText::FromString(FString::FromInt(CurrentHP)));
	CharacterMaxHP->SetText(FText::FromString(FString::FromInt(MaxHP)));

	HP_ProgressBar->SetPercent(HP_Percentage);
}

void UCombatStatusWidget::ManageMP()
{
	int32 CurrentMP = *CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("CurrentMP");
	int32 MaxMP = *CombatHUD->CombatPlayerCharacter->CPC_StatMap.Find("MaxMP");

	float MP_Percentage = float(CurrentMP) / float(MaxMP);

	CharacterCurrentMP->SetText(FText::FromString(FString::FromInt(CurrentMP)));
	CharacterMaxMP->SetText(FText::FromString(FString::FromInt(MaxMP)));

	MP_ProgressBar->SetPercent(MP_Percentage);
}

void UCombatStatusWidget::ATB_TimeBarFill()
{
	//UE_LOG(LogTemp, Warning, TEXT("ATB %f out of %f"), CombatHUD->ATB_Component->CurrentATB_Fill, CombatHUD->ATB_Component->MaxATB_Fill)
	//return CombatHUD->ATB_Component->CurrentATB_Fill / CombatHUD->ATB_Component->MaxATB_Fill;
	ATB_Bar->SetPercent(CombatHUD->ATB_Component->CurrentATB_Fill / CombatHUD->ATB_Component->MaxATB_Fill);
}

FLinearColor UCombatStatusWidget::ATB_TimeBarTint()
{
	if (CombatHUD->ATB_Component)
	{
		if (CombatHUD->ATB_Component->CurrentATB_Fill >= CombatHUD->ATB_Component->MaxATB_Fill)
		{
			return FLinearColor(1.f, 0.950155f, 0.234393f, 1.f);
		}
		else
		{
			return FLinearColor(0.208059f, 1.f, 0.278838f, 1.f);
		}
	}
	else
	{
		return FLinearColor(0.f, 0.f, 0.f);
	}
}