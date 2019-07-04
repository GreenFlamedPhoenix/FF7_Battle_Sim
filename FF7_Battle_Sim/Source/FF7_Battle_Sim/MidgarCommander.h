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
	AMidgarCommander();
	virtual void BeginPlay() override;
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;

	UPROPERTY()
	UATB_Component* ATB_Component;

	UFUNCTION()
	void ReadyForAction();

	UFUNCTION()
	void ResetEnemyInfoStats();

	UPROPERTY()
	bool bReadyForAction;

	//////////////////////////////
	//	Stats
	//	Base stats
	//////////////////////////////

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 MyLevel = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 CurrentHP = 200;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 MaxHP = 200;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 CurrentMP = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 MaxMP = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 Dexterity = 13;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 ExpWorth = 20;
};