// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyBase.generated.h"
class USkeletalMeshComponent;
class USceneComponent;
class ACombatPlayerCharacterController;

UCLASS()
class FF7_BATTLE_SIM_API AEnemyBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* MyRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY()
	ACombatPlayerCharacterController* CombatController;

	UFUNCTION()
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent);

	UFUNCTION()
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bEnemyHovered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* CursorActor;
};
