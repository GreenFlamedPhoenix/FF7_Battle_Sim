// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"
class APlayerCharacter;
class ACameraActor;
class UMainGameInstance;
class AWorldMapMode;
class AWorldMenuHUD;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	/*Getting the GameMode to set references for the level.*/
	UPROPERTY()
	AWorldMapMode* WorldMapGameMode;

	/*Sets the ControlledCharacter once the character spawns.*/
	UFUNCTION()
	void SetPlayerCharacter(APlayerCharacter* inPlayerCharacter);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	APlayerCharacter* ControlledCharacter;

	/*The GameInstance, which holds info when transitioning between combat.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	UMainGameInstance* GameInstance;

	/*The Camera that I am currently possessing.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "References")
	ACameraActor* MyCurrentCamera;

	UPROPERTY()
	AWorldMenuHUD* MenuHUD;

	

private:
	UFUNCTION()
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void SetupInputComponent() override;

	/*Sets our current camera that we need to possess.*/
	UFUNCTION(BlueprintCallable)
	void SetMapCamera(ACameraActor* MapCamera);

	/*Boolean to ensure we don't increase the combat chance twice at once.*/
	UPROPERTY()
	bool bIncreasingCombatChance;

	/*Basic movement functions.*/
	UFUNCTION()
	void MoveForward(float Axis);

	UFUNCTION()
	void MoveRight(float Axis);

	UFUNCTION()
	void ToggleMenu();
};