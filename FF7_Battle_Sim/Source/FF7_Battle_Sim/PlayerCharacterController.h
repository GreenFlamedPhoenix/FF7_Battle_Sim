// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"
class APlayerCharacter;
class ACameraActor;
class UMainGameInstance;
class AWorldMapMode;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AWorldMapMode* WorldMapGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	UMainGameInstance* GameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "References")
	ACameraActor* MyCurrentCamera;

	UFUNCTION(BlueprintCallable)
	void SetPlayerCharacter(APlayerCharacter* inPlayerCharacter);

private:
	UFUNCTION()
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
	void SetMapCamera(ACameraActor* MapCamera);



	UFUNCTION()
	void MoveForward(float Axis);

	UFUNCTION()
	void MoveRight(float Axis);

	UPROPERTY()
	bool bIncreasingCombatChance;
};