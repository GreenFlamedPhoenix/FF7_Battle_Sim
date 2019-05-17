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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	UMainGameInstance* GameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "References")
	ACameraActor* MyCurrentCamera;

	UFUNCTION()
	void MoveForward(float Axis);

	UFUNCTION()
	void MoveRight(float Axis);

	UPROPERTY()
	bool bIncreasingCombatChance;

	UFUNCTION(BlueprintCallable)
	void SetMapCamera(ACameraActor* MapCamera);
	
};
