// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (CharacterController != nullptr)
	{
		CharacterController->SetPlayerCharacter(this);
	}
}