// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "CombatInterface.h"
#include "MidgarSoldier.generated.h"
class ACombatGameMode;
class UATB_Component;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMidgarSoldier : public AEnemyBase
{
	GENERATED_BODY()

public:
	AMidgarSoldier();

	virtual void BeginPlay() override;

	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;

	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;

	virtual void Attack() override;

	UPROPERTY()
	UATB_Component* ATB_Component;

	UFUNCTION()
	void ResetEnemyInfoStats();

	UFUNCTION(BlueprintCallable)
	void DrinkPotion();

	UFUNCTION()
	void ReadyToAttack();

	//////////////////////////////
	//	Stats
	//	Base stats
	//////////////////////////////

	

	//////////////////////////////
	//	Inventory
	//	Inventory items.
	//////////////////////////////

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 PotionsRemaining = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bReadyForAction;
};
