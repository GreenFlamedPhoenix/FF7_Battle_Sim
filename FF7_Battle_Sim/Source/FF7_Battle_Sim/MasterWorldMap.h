// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MasterWorldMap.generated.h"
class UWorldMenuMainWidget;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API AMasterWorldMap : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UFUNCTION()
	void SetWorldMenuMainWidget(UWorldMenuMainWidget* inWorldMainMenuWidget);

	UFUNCTION()
	virtual FString GetMapName();
};
