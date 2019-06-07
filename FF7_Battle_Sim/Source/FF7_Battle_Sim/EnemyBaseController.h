// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyBaseController.generated.h"

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AEnemyBaseController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float BaseActionFillRate = .5f;

	//UPROPERTY()
	//FTimerHandle ActionTimer;
	
};