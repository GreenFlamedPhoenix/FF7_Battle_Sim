// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"
class APlayerCharacter;
class APlayerCharacterController;
class ACameraActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCombatTriggered);

UENUM(BlueprintType)
enum class EMapThemeEnum : uint8
{
	MidgarStreetsTheme		UMETA(DisplayName = "MidgarStreetsTheme"),
	ForestTheme				UMETA(DisplayName = "ForestTheme")
};

UENUM(BlueprintType)
enum class EMapTransitionEnum : uint8
{
	InitialSpawn			UMETA(DisplayName = "InitialSpawn"),
	SpawnFromCombat			UMETA(DisplayName = "SpawnFromCombat"),
	SpawnTo1				UMETA(DisplayName = "SpawnTo1"),
	SpawnTo2				UMETA(DisplayName = "SpawnTo2"),
	SpawnTo3				UMETA(DisplayName = "SpawnTo3"),
	SpawnTo4				UMETA(DisplayName = "SpawnTo4")
};

UCLASS()
class FF7_BATTLE_SIM_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EMapThemeEnum MapThemeEnum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EMapTransitionEnum MapTransitionEnum;

	UFUNCTION()
	void SetCharacterReference();

	UFUNCTION()
	void SetPlayerControllerReference();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacterController* CharacterController;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACameraActor* SavedCamera;
};
