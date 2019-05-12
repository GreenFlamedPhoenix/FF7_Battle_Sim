// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningLevel.h"
#include "PlayerCharacter.h"
#include "CombatTrackingComponent.h"
#include "Kismet/GameplayStatics.h"

AOpeningLevel::AOpeningLevel()
{
	
}

void AOpeningLevel::BeginPlay()
{
	Super::BeginPlay();

	bCombatMap = true;

	ControlledCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (ControlledCharacter == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null ControlledCharacter from Level")); return;}
	else {UE_LOG(LogTemp, Warning, TEXT("Player character good from level!"));}
	PlayersCombatComponent = ControlledCharacter->FindComponentByClass<UCombatTrackingComponent>();
	if (PlayersCombatComponent == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null ControlledCharacter from Level")); return;}
	else {UE_LOG(LogTemp, Warning, TEXT("Characters combat component good from level!"));}
	PlayersCombatComponent->SetMapCombatState(bCombatMap);
}