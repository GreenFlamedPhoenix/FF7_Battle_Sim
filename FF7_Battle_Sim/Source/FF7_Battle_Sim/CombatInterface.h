// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"
class ACombatPlayerCharacter;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FF7_BATTLE_SIM_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/*
	ACombatPlayerCharacter* CombatCharacter;

	int32 Strength;

	int32 Luck;

	int32 MyLevel;

	UFUNCTION()
	virtual void SetCombatCharacter(ACombatPlayerCharacter* inCharacter);

	UFUNCTION()
	virtual void Attack();

	*/
};