// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "MidgarSoldier.generated.h"

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMidgarSoldier : public AEnemyBase
{
	GENERATED_BODY()

public:
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent) override;

	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent) override;
	
};
