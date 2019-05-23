// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WorldMapMode.generated.h"
class APlayerCharacterController;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AWorldMapMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void SetWorldPlayerController(APlayerCharacterController* inWorldPlayerController);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APlayerCharacterController* WorldPlayerController;
};
