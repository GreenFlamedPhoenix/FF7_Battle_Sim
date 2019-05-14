// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatTrackingComponent.generated.h"
class ULevel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FF7_BATTLE_SIM_API UCombatTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatTrackingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULevel* CurrentLevel;

	void SetMapCombatState(bool bCombatMap);

	/*Whether we are in a combat map or a safe map with no combat chance.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCurrentlyInCombatMap;

	/*Our current chance between 1 & 100 to enter combat.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentCombatChance = 0.f;

	/*Our highest possible chance to enter combat, obviously 100% chance.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxCombatChance = 100.f;

	void ManageCombatChance();
};
