// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.h"
#include "CombatPlayerCharacter.generated.h"
class ACombatPlayerCharacterController;
class AEnemyBase;

//TODO Continue work on MoveTo for attacking.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMoveToAttack, AEnemyBase*, AttackTarget);

UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACombatPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable)
	FMoveToAttack MoveToAttack;

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToAttack_Implementation(AEnemyBase* AttackTarget);
};