// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"
class UMainGameInstance;
class ACombatPlayerCharacter;
class ACombatHUD;

UCLASS()
class FF7_BATTLE_SIM_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

public:
	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	ACombatHUD* CombatHUD;

	UPROPERTY()
	ACombatPlayerCharacter* CombatCharacter;

	UFUNCTION(BlueprintCallable)
	virtual void UseItem();
};