// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "MidgarSoldier.generated.h"
//class ACombatGameMode;
//class UATB_Component;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMidgarSoldier : public AEnemyBase
{
	GENERATED_BODY()

public:
	//////////////////////////////
	//	Constructor
	//////////////////////////////
	AMidgarSoldier();

	/*ATB Component for managing ticking up for their turn. Created on construction.*/
	//UPROPERTY(VisibleAnywhere)
	//UATB_Component* ATB_Component;



	//////////////////////////////
	// Overridden functions for the parent EnemyBase class.
	//////////////////////////////
	virtual void BeginPlay() override;
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;
	virtual void Attack() override;



	//////////////////////////////
	// ATB Control
	//////////////////////////////

	/*Function triggered when the ATB becomes full. Sets the ReadyForAction boolean. */
	UFUNCTION()
	void EnemyATB_Full();

	/*Boolean used by the behavior tree to dictate if they can use their turn.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bSoldierReadyForAction;

	

	//////////////////////////////
	//	Enemy inventory and inventory functions.
	//////////////////////////////

	/*Potions remaining in the soldiers inventory to use.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 PotionsRemaining = 1;

	/*Function called by the behavior tree when the soldier wants to drink a potion.*/
	UFUNCTION(BlueprintCallable)
	void DrinkPotion();



	//////////////////////////////
	//	Misc functions.
	//////////////////////////////

	/*Shorthand function for resetting the view for the EnemyInfoWidget. Just to make things neater.*/
	UFUNCTION()
	void ResetEnemyInfoStats();
};