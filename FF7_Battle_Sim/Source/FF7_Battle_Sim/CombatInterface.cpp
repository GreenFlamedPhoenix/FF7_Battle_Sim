// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatInterface.h"
#include "CombatPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

/*
void ICombatInterface::SetCombatCharacter(ACombatPlayerCharacter* inCharacter)
{
	CombatCharacter = inCharacter;
}

// Add default functionality here for any ICombatInterface functions that are not pure virtual.
void ICombatInterface::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack"));
	if (CombatCharacter)
	{
		

		//Add into account player defenses
		float DamageReductionPercentage = ((*CombatCharacter->CPC_StatMap.Find("Vitality") * 5) / 1700);
		float DamageReduction = FinalDamageDealt * DamageReductionPercentage;
		int32 DamageToRecieve = FMath::FloorToInt(FinalDamageDealt - DamageReduction);

		UE_LOG(LogTemp, Warning, TEXT("Player took %i damage"), DamageToRecieve);
		CombatCharacter->CPC_StatMap.Emplace("CurrentHP") = *CombatCharacter->CPC_StatMap.Find("CurrentHP") - DamageToRecieve;
	}
} */