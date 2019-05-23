// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatPlayerCharacter.generated.h"

UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
