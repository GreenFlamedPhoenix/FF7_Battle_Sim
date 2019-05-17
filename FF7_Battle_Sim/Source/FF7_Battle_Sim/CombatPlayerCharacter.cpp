// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacter.h"

// Sets default values
ACombatPlayerCharacter::ACombatPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACombatPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACombatPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACombatPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

