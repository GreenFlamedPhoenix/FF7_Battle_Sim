// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ATB_Component.generated.h"
class USoundCue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FATB_Full);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FF7_BATTLE_SIM_API UATB_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UATB_Component();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	//////////////////////////////////////////////////
	// ATB Setup
	// Things used to set up the owners ATB.
	//////////////////////////////////////////////////

	//The equation to determine speed, or how much to fill the owners ATB bar each .1 seconds.
	UFUNCTION()
	void CalculateATB_FillSpeed(int32 inDexterity, int32 inStatusMultiplier);	// Equation (Dexterity / 3 + 375 * 0.6) * Status multiplier.

	// The float returned from CalculateATB_FillSpeed().
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float ATB_FillSpeed;

	// The handle for the timer that counts the initial delay before beginning to fill everyones ATB.
	UPROPERTY()
	FTimerHandle ATB_DelayTimer;

	// The function called from the ATB_DelayTimer.
	UFUNCTION()
	void TickATB_Delay();

	// Delay timer integer for the ATB_DelayTimer.
	UPROPERTY()
	int32 DelayTimer;

	// Function that determines how full the ATB bar is at the start of combat. Players are over 75% initially, enemies start empty.
	UFUNCTION()
	void DetermineATB_InitialFill(bool bIsPlayer);

	// Bolean for the component to remeber if its owned by a player or not.
	UPROPERTY()
	bool bOwnedByPlayer;


	//////////////////////////////////////////////////
	// ATB functionality.
	// Things that control the running of the ATB, after initial setup.
	//////////////////////////////////////////////////

	// How full our ATB bar currently is.
	UPROPERTY()
	float CurrentATB_Fill;

	// The max out ATB can reach. Once at this level we can choose an action.
	UPROPERTY()
	float MaxATB_Fill = 100.f;

	// Timer handle for our function that fills the ATB bar.
	UPROPERTY()
	FTimerHandle ATB_FillTimer;

	// Function called by the ATB_FillTimer that fills the ATB bar by the ATB_FillSpeed.
	UFUNCTION()
	void TickUpATB();
	
	// Boolean telling if we are ready to choose and action or not.
	UPROPERTY()
	bool bOwnerActionReady;

	// Event that fires when our ATB bar becomes full.
	UPROPERTY()
	FATB_Full ATB_FullEvent;
	
	// Function to quickly reset the ATB bar to empty and filling.
	UFUNCTION()
	void ResetATB();

	//Display the ActionMenuWidget if you are a player character.
	UFUNCTION()
	void DisplayActionenuWidget();

	UPROPERTY()
	USoundCue* ATB_ReadySoundCue;
};