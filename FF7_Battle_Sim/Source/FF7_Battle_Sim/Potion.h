// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Potion.generated.h"


/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API APotion : public AItemBase
{
	GENERATED_BODY()

public:
	virtual void UseItem() override;
};
