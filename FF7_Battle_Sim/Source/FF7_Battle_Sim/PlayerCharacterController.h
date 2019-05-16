// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"
class APlayerCharacter;
class ACameraActor;
class UMainGameInstance;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY()
	APlayerCharacter* ControlledCharacter;
	UPROPERTY()
	UMainGameInstance* GameInstance;

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	UPROPERTY()
	bool bIncreasingCombatChance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ACameraActor* MyCurrentCamera;

	UFUNCTION(BlueprintCallable)
	void SetMapCamera(ACameraActor* MapCamera);
	
};
