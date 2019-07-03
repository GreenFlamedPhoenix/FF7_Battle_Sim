// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatItemMenu.h"
#include "CombatHUD.h"

void UCombatItemMenu::SetCombatHUD(ACombatHUD* inHUD)
{
	CombatHUD = inHUD;
}

void UCombatItemMenu::UpdatePotionQuantity()
{
	PotionQuantity->SetText(FText::FromString(FString::FromInt(*CombatHUD->MainGameInstance->ItemInventory.Find("Potion"))));
}