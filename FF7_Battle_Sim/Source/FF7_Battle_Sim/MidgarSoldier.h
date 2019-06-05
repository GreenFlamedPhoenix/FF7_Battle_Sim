// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "MidgarSoldier.generated.h"
class ACombatGameMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMidgarSoldier : public AEnemyBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	FString SetEnemyLevel();

	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;
	
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;

	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey) override;

	UPROPERTY()
	FString MyLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentMP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMP;
};
