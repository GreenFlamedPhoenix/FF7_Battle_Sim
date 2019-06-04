// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatInterface.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerCharacterController.generated.h"
class AEnemyBase;
class UActionMenuWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FATB_Ready);

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	//////////////////////////////
	//	Reference pointers.
	//	Pointers to hold our many basic references and their setters.
	//////////////////////////////

	//Pointer for our EnemyBase. Used by its children classes for hover events.
	UPROPERTY()
	AEnemyBase* EnemyBaseReference;

	//Pointer for ActionMenu reference. Used with the attack command.
	UPROPERTY()
	UActionMenuWidget* ActionMenuWidget;

	//Reference setters.
	UFUNCTION()
	void SetActionMenuWidget(UActionMenuWidget* Widget);
	UFUNCTION()
	void SetEnemyBaseReference(AEnemyBase* EnemyBase);

	//////////////////////////////
	//	ATB Timer.
	//	Attributes for the action timer for the character.
	//////////////////////////////

	//Our current float that makes up our action timer we are at now.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentActionTimer;

	//Our max the timer can be at. Once at max we are ready to do an action.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxActionTimer = 25;

	//Variable that holds our timer that increments our ActionTimer.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTimerHandle ActionCountTimer;

	//Function called by our timer that actually controls the functionality of managing the ATB.
	UFUNCTION()
	void CountUpActionTimer();

	//Function that resets everything for our ATB. Sets CurrentActionTimer and un-pauses the timer.
	UFUNCTION()
	void ResetActionTimer();

	//Event triggered when our CurrentActionTimer hits max, meaning we are ready for our action.
	UPROPERTY(BlueprintAssignable)
	FATB_Ready ATB_Ready;

	//////////////////////////////
	//	Misc stuff.
	//	Stuff just for testing or serve no actual functional purpose just yet.
	//////////////////////////////

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemianingPhysBarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemainingM_BarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxBarrierDuration = 60.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bHoveringEnemy;
};