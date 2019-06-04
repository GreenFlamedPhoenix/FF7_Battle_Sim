// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStatusWidget.h"
#include <Kismet/GameplayStatics.h>
#include "CombatPlayerCharacterController.h"

UCombatStatusWidget::UCombatStatusWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UCombatStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}

void UCombatStatusWidget::SetCurrentHP(int32 CurrentHP)
{

}

void UCombatStatusWidget::SetCurrentMP(int32 CurrentMP)
{

}

float UCombatStatusWidget::ATB_TimeBarFill()
{
	return CombatController->CurrentActionTimer / 25.f;
}

FLinearColor UCombatStatusWidget::ATB_TimeBarTint()
{
	if (CombatController->CurrentActionTimer == 25.f)
	{
		return FLinearColor(1.f, 0.950155f, 0.234393f, 1.f);
	}
	else
	{
		return FLinearColor(0.208059f, 1.f, 0.278838f, 1.f);
	}
}