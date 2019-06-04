// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatInterface.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerCharacterController.generated.h"
class ACombatThemeMaps;
class ACombatGameMode;
class AEnemyBase;
class UEnemyInfoWidget;
class UActionMenuWidget;
class UCombatInterface;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FATB_Ready);

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatPlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	ACombatGameMode* CombatGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTimerHandle ActionCountTimer;

	UFUNCTION(BlueprintCallable)
	void CountUpActionTimer();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentActionTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxActionTimer = 25;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bReadyForAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemianingPhysBarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RemainingM_BarrierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxBarrierDuration = 60.f;

	ACombatThemeMaps* CurrentMap;

	UFUNCTION(BlueprintCallable)
	void TriggerCountUpTimer();

	UPROPERTY(BlueprintAssignable)
	FATB_Ready ATB_Ready;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bHoveringEnemy;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* HoveredActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AEnemyBase* EnemyBaseReference;

	UFUNCTION()
	void SetEnemyBaseReference(AEnemyBase* EnemyBase);

	UPROPERTY()
	UEnemyInfoWidget* EnemyInfoWidget;

	UFUNCTION()
	void SetEnemyInfoWidget(UEnemyInfoWidget* Widget);

	UPROPERTY()
	UActionMenuWidget* ActionMenuWidget;

	UFUNCTION()
	void SetActionMenuWidget(UActionMenuWidget* Widget);

	UFUNCTION()
	void BeginAttack();

	UFUNCTION()
	void ResetActionTimer();
};