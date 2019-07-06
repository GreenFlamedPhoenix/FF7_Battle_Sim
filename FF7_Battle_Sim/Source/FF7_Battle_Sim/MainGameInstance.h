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
	SpawnFromLoad			UMETA(DisplayName = "SpawnFromLoad"),
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

	/*Reference for the PlayerCharacter. */
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


	//////////////////////////////
	// Combat control functions and variables.
	// TODO Look into possibly moving this to its own component.
	//////////////////////////////

	/*Sets whether our current map is flagged for combat.*/
	UFUNCTION()
	void SetMapCombatState(bool bCombatMap);

	/*Boolean for whether our current map is flagged for combat or not.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCurrentlyInCombatMap;

	/*Our current chance to enter combat. Increases as we walk around.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentCombatChance;

	/*The highest our combat chance can get. Obviously 100% chance.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxCombatChance = 100.f;

	/*Function called to control combat being triggered.*/
	UFUNCTION(BlueprintCallable)
	void BeginCombat();

	/*Timer that generates random numbers for the purpose of triggering combat.*/
	UPROPERTY()
	FTimerHandle RandomNumberCounter;

	/*Function called by the RandomNumberCounter timer that generates the number for combat triggering.*/
	UFUNCTION()
	void GenerateRandomCombatRoll();

	/*Variable to hold our current generated roll*/
	UPROPERTY()
	float CombatChanceRoll = 0.f;

	/*Boolean tracking when combat gets triggered.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bCombatTriggered;

	/*Keep track of the characters location for respawn after combat.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform SavedCombatTransform;

	/*Event to broadcast once combat triggers.*/
	UPROPERTY(BlueprintAssignable)
	FCombatTriggered CombatTriggered;

	UFUNCTION(BlueprintCallable)
	void ClearGameInstance();

	UFUNCTION()
	void ManageCombatChance();

	/*The camera we were possessing before combat was triggered.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString SavedCameraName;


	//////////////////////////////
	// Game played timer control.
	//////////////////////////////

	/*Function that begins the game played counter at the proper time.*/
	UFUNCTION(BlueprintCallable)
	void StartGamePlayedTimer();

	/*The actual timer for ticking up the time played counter.*/
	UPROPERTY()
	FTimerHandle GameTimeCounter;

	/*The function called by the timer responsible for actually ticking up the time played counter,*/
	UFUNCTION()
	void CountUpPlayedTimer();

	/*Variables for the different played counter digits.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SecondsPlayedOne;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SecondsPlayedTwo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MinutesPlayedOne;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MinutesPlayedTwo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HoursPlayedOne;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HoursPlayedTwo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DaysPlayedOne;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DaysPlayedTwo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DaysPlayedThree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DaysPlayedFour;
	

	//////////////////////////////
	// Player attributes storage.
	//////////////////////////////

	/*Map holding all of out characters stats and attributes.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FString, int32> MGI_StatMap;

	/*Current Gil for the player*/ //TODO Look into moving this into the Stat Map.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CureentGil = 100;

	/*Inventory of the player*/ //TODO Inventory not implemented in any real capacity.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FString, int32> ItemInventory;

	/*Variable to store the players spawn when loading a game.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTransform LoadedPlayerTransform;


	//////////////////////////////
	// Map information storage.
	//////////////////////////////

	/*The map name as the player would know it.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString CurrentProperMapName;

	/*The map name as the engine knows it in regards to opening levels.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName CurrentWorldMapFName;

	/*Function called when combat completes.*/
	UFUNCTION(BlueprintCallable)
	void CompleteCombat();






	
	//////////////////////////////
	// Possible things to remove.
	//////////////////////////////

	//UPROPERTY()
	//int32 CharacterOneCurrentExp;

	//UPROPERTY()
	//int32 CharacterOneExpToNext;

	//UPROPERTY()
	//int32 PlayerOneCurrentExp = 1990;

	//UPROPERTY()
	//int32 PlayerOneExpToLevel = 2000;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//int32 PlayerOneLevel = 1;

	//UPROPERTY()
	//int32 GI_PlayerStrength = 1;

	//UPROPERTY()
	//int32 GI_PlayerDexterity = 1;

	//UPROPERTY()
	//int32 GI_PlayerVitality = 1;

	//UPROPERTY()
	//int32 GI_PlayerMagic = 1;

	//UPROPERTY()
	//int32 GI_PlayerSpirit = 1;

	//UPROPERTY()
	//int32 GI_PlayerLuck = 1;

	//UPROPERTY()
	//FName MapFName;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int32 CharacterOneCurrentHP = 140;

	//UPROPERTY()
	//int32 MaxHP = 140;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int32 CharacterOneCurrentMP = 40;

	//UPROPERTY()
	//int32 CharacterOneMaxMP = 40;






	UPROPERTY()
	int32 ExpToAward;



	UPROPERTY()
	int32 ExpToHold;

	UFUNCTION()
	void CalculatePlayerExp(int32 inAwardedExp);



	UFUNCTION()
	void LevelUp();







};