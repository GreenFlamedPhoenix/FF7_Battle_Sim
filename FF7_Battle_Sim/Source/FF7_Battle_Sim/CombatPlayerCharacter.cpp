// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacter.h"

ACombatPlayerCharacter::ACombatPlayerCharacter()
{
	
}

// Called when the game starts or when spawned
void ACombatPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	MoveToAttack.AddDynamic(this, &ACombatPlayerCharacter::MoveToAttack_Implementation);
}