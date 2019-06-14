// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 MyLevel = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentHP = 120;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHP = 120;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentMP = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMP = 20;

	UPROPERTY()
	int32 Dexterity = 10;

	//////////////////////////////
	//	Inventory
	//	Inventory items.
	//////////////////////////////

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 PotionsRemaining = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bReadyForAction;
};
