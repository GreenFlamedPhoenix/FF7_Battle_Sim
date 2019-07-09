// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "MidgarCommander.generated.h"
//class UATB_Component;

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



	//////////////////////////////
	// Overridden functions for the parent EnemyBase class.
	//////////////////////////////
	virtual void BeginPlay() override;
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;
	virtual void Attack() override;



	//////////////////////////////
	// Misc. functions
	//////////////////////////////

	/*Shorthand function for resetting the view for the EnemyInfoWidget. Just to make things neater.*/
	UFUNCTION()
	void ResetEnemyInfoStats();
};