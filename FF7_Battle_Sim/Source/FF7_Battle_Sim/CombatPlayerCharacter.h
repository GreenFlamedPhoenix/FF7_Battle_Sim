// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.h"
#include "CombatPlayerCharacter.generated.h"
class ACombatPlayerCharacterController;
class AEnemyBase;
class ACombatGameMode;
class UATB_Component;
class ACombatHUD;

UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACombatPlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UATB_Component* ATB_Component;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 Dexterity = 28;

	UFUNCTION()
	void ReadyForAction();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACombatGameMode* CombatGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bCombatFinished;

	UPROPERTY()
	ACombatHUD* CombatHUD;
};