// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerLevelComponent.generated.h"
class UMainGameInstance;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FF7_BATTLE_SIM_API UPlayerLevelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerLevelComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;
};
