// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"

ACombatPlayerCharacter::ACombatPlayerCharacter()
{
	
}

// Called when the game starts or when spawned
void ACombatPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	CombatGameMode->SetCombatCharacter(this);

	//MoveToAttack.AddDynamic(this, &ACombatPlayerCharacter::MoveToAttack_Implementation);
}