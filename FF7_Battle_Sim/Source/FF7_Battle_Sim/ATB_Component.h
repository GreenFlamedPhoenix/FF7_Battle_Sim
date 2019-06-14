// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ATB_Component.generated.h"

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
	UPROPERTY()
	float ATB_FillSpeed;

	UPROPERTY()
	float CurrentATB_Fill;

	UPROPERTY()
	float MaxATB_Fill = 1000.f;

	//Possible speed equation (Dexterity / 3 + 375 * 0.6 ) * Status multiplier
	UFUNCTION()
	void CalculateATB_FillSpeed(int32 inDexterity, int32 inStatusMultiplier);

	UPROPERTY()
	FTimerHandle ATB_FilTimer;

	UPROPERTY()
	FTimerHandle ATB_DelayTimer;

	UFUNCTION()
	void TickATB_Delay();

	UFUNCTION()
	void TickUpATB();

	UFUNCTION()
	void DetermineATB_InitialFill(bool bIsPlayer);

	UPROPERTY()
	int32 DelayTimer;
	
	UPROPERTY()
	bool bOwnerActionReady;

	UPROPERTY()
	FATB_Full ATB_Full;
};