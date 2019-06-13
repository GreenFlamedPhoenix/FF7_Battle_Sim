// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ATB_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FF7_BATTLE_SIM_API UATB_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UATB_Component();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	
	//Possible speed equation (Dexterity / 4 + 450 * 0.6 ) * Status multiplier
		
};
