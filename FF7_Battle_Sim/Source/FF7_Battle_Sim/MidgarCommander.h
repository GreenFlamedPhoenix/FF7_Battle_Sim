// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "MidgarCommander.generated.h"
class UATB_Component;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMidgarCommander : public AEnemyBase
{
	GENERATED_BODY()

public:
	//////////////////////////////
	//	Constructor
	//////////////////////////////
	AMidgarCommander();

	/*ATB Component for managing ticking up for their turn. Created on construction.*/
	UPROPERTY()
	UATB_Component* ATB_Component;



	//////////////////////////////
	// Overridden functions for the parent EnemyBase class.
	//////////////////////////////
	virtual void BeginPlay() override;
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;
	//TODO Attack function.



	//////////////////////////////
	// ATB Control
	//////////////////////////////

	/*Function triggered when the ATB becomes full. Sets the ReadyForAction boolean. */
	UFUNCTION()
	void ATB_Full();

	/*Boolean used by the behavior tree to dictate if they can use their turn.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bReadyForAction;



	//////////////////////////////
	// Misc. functions
	//////////////////////////////

	/*Shorthand function for resetting the view for the EnemyInfoWidget. Just to make things neater.*/
	UFUNCTION()
	void ResetEnemyInfoStats();
};