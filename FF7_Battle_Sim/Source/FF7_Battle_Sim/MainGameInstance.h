// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"
class APlayerCharacter;
class APlayerCharacterController;
class ACameraActor;
class UEnemyInfoWidget;
class UActionMenuWidget;
class UWorldMenuMainWidget;

/*Event to broadcast when combat triggers.*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCombatTriggered);

/*Enum for tracking the current map. Used when determining what combat map to open.*/
UENUM(BlueprintType)
enum class EMapThemeEnum : uint8
{
	MidgarStreetsTheme		UMETA(DisplayName = "MidgarStreetsTheme"),
	ForestTheme				UMETA(DisplayName = "ForestTheme")
};

/*Enum used for determining what door we entered, to make sure to spawn us at the right door in the next area.*/
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
	virtual void Init() override;

	//////////////////////////////
	// Enum Variables.
	// Variable names for our Enums.
	//////////////////////////////

	//Controls the map theme so we know which combat map to spawn on during combat start.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EMapThemeEnum MapThemeEnum;

	//Controls remember what doors we travel through so it knows which door to spawn us on in the next room.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EMapTransitionEnum MapTransitionEnum;

	//////////////////////////////
	// Reference Pointers
	// Pointers and setters for base references.
	//////////////////////////////

	//TODO Do we need this?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacterController* CharacterController;

	UPROPERTY()
	UEnemyInfoWidget* EnemyInfoWidget;

	UPROPERTY()
	UActionMenuWidget* PlayerActionMenuWidget;

	UPROPERTY()
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UFUNCTION(BlueprintCallable)
	void SetCharacterReference(APlayerCharacter* inPlayerCharacter);

	UFUNCTION(BlueprintCallable)
	void SetPlayerControllerReference(APlayerCharacterController* inPlayerController);

	UFUNCTION()
	void SetEnemyInfoWidget(UEnemyInfoWidget* Widget);

	UFUNCTION()
	void SetActionMenuWidget(UActionMenuWidget* Widget);

	UFUNCTION()
	void SetWorldMenuMainWidget(UWorldMenuMainWidget* inWidget);

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
	FTransform SavedCombatTransform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString SavedMapName;

	UPROPERTY()
	FName MapFName;

	UFUNCTION(BlueprintCallable)
	void CompleteCombat(FName SavedMapFName);

	UPROPERTY(BlueprintAssignable)
	FCombatTriggered CombatTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString SavedCameraName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CharacterOneCurrentHP = 140;

	UPROPERTY()
	int32 CharacterOneMaxHP = 140;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CharacterOneCurrentMP = 40;

	UPROPERTY()
	int32 CharacterOneMaxMP = 40;

	UPROPERTY()
	FTimerHandle GameTimeCounter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 SecondsPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 MinutesPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 HoursPlayed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 DaysPlayed;

	UFUNCTION()
	void CountUpPlayedTimer();

	
};
