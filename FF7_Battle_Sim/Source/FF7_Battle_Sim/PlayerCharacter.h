// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
class APlayerCharacterController;

UCLASS()
class FF7_BATTLE_SIM_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	APlayerCharacterController* CharacterController;
};
