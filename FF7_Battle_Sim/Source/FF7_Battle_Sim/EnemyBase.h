// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatInterface.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"
class UMainGameInstance;
class ACombatPlayerCharacterController;
class UEnemyInfoWidget;
class UActionMenuWidget;



UCLASS()
class FF7_BATTLE_SIM_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CharacterCapsule;

	UPROPERTY()
	ACombatPlayerCharacterController* CombatController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* HoveredActor;

	UFUNCTION()
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent);

	UFUNCTION()
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCurrentlyOverEnemy;

	UPROPERTY()
	UEnemyInfoWidget* EnemysEnemyInfoWidget;

	UPROPERTY()
	UActionMenuWidget* ActionMenuWidget;

	UFUNCTION()
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey);
};