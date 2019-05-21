// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"
class APlayerCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCombatTriggered);

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetCharacterReference();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	UFUNCTION()
	void SetMapCombatState(bool bCombatMap);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCurrentlyInCombatMap;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentCombatChance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxCombatChance = 100.f;

	UFUNCTION()
	void ManageCombatChance();

	UFUNCTION(BlueprintCallable)
	void BeginCombat();

	UPROPERTY()
	FTimerHandle RandomNumberCounter;

	UFUNCTION()
	void GenerateRandomCombatRoll();

	UPROPERTY()
	float CombatChanceRoll = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bCombatTriggered;

	/*Keep track of the characters location for respawn after combat.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector SavedCombatLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString SavedMapName;

	UFUNCTION(BlueprintCallable)
	void CompleteCombat(FName SavedMapFName);

	UPROPERTY(BlueprintAssignable)
	FCombatTriggered CombatTriggered;
};
