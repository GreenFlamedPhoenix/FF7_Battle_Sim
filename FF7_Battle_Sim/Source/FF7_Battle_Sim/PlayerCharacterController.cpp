// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	ControlledCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (ControlledCharacter == nullptr) {UE_LOG(LogTemp, Error, TEXT("ControlledCharacter from controlled is null!")); return;}
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	/*Movement Bindings*/
	InputComponent->BindAxis("MoveForward", this, &APlayerCharacterController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacterController::MoveRight);
}

void APlayerCharacterController::MoveForward(float Axis)
{
	if (Axis != 0.f)
	{
		float ClampedAxis = FMath::Clamp(Axis, -1.f, 1.f);
		FVector Direction = ControlledCharacter->GetActorForwardVector();
		ControlledCharacter->AddMovementInput(Direction, ClampedAxis);
	}
}

void APlayerCharacterController::MoveRight(float Axis)
{
	if (Axis != 0.f)
	{
		float ClampedAxis = FMath::Clamp(Axis, -1.f, 1.f);
		FVector Direction = ControlledCharacter->GetActorRightVector();
		ControlledCharacter->AddMovementInput(Direction, ClampedAxis);
	}
}