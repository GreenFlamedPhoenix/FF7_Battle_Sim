// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
#include "ATB_Component.h"
#include "CombatHUD.h"

void APotion::UseItem()
{
	if (MainGameInstance && CombatHUD && CombatHUD)
	{
		CombatCharacter->CPC_StatMap.Emplace("CurrentHP") = *CombatCharacter->CPC_StatMap.Find("CurrentHP") + 50;
		MainGameInstance->ItemInventory.Emplace("Potion") = *MainGameInstance->ItemInventory.Find("Potion") - 1;
		CombatCharacter->ATB_Component->ResetATB();
		CombatHUD->CombatItemMenuWidget->UpdatePotionQuantity();
		CombatHUD->CombatItemMenuWidget->RemoveFromViewport();
	}
}