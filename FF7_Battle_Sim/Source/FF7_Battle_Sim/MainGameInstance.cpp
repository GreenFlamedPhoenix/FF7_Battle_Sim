// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

/*Gets whether or not this is a combat map from the level*/
void UMainGameInstance::SetMapCombatState(bool bCombatMap)
{
	bCurrentlyInCombatMap = bCombatMap;
}

void UMainGameInstance::ManageCombatChance()
{
	if (bCurrentlyInCombatMap == true)
	{
		CurrentCombatChance += .09f;

		if (CurrentCombatChance >= 25.f)
		{
			if (GetWorld()->GetTimerManager().IsTimerActive(RandomNumberCounter))
			{
				if (CurrentCombatChance > CombatChanceRoll && CombatChanceRoll != 0.f)
				{
					BeginCombat();
				}
				else
				{
					return;
				}
			}
			else
			{
				GetWorld()->GetTimerManager().SetTimer(RandomNumberCounter, this, &UMainGameInstance::GenerateRandomCombatRoll, true, 1.f);
			}
		}
	}
}

void UMainGameInstance::GenerateRandomCombatRoll()
{
	CombatChanceRoll = FMath::RandRange(25.f, 100.f);
}

void UMainGameInstance::BeginCombat()
{
	UE_LOG(LogTemp, Warning, TEXT("Entered combat!"));
	GetWorld()->GetTimerManager().ClearTimer(RandomNumberCounter);
	CurrentCombatChance = 0.f;
	CombatChanceRoll = 0.f;
	bCombatTriggered = true;
}