// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "MainGameInstance.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	/*Find the character we are controlling*/
	ControlledCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (ControlledCharacter == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null Character from PlayerController!")); return;}

	/*Find the CombatTrackingComponent for our character*/
	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (GameInstance == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameInstance from PlayerController!")); return;}
}

/*Function to be able to easily set the camera we are using for character movement.*/
void APlayerCharacterController::SetMapCamera(ACameraActor* MapCamera)
{
	MyCurrentCamera = MapCamera;
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
	if (MyCurrentCamera != nullptr)
	{
		if (Axis != 0.f)
		{
			float ClampedAxis = FMath::Clamp(Axis, -1.f, 1.f);
			FVector Direction = MyCurrentCamera->GetActorForwardVector();
			ControlledCharacter->AddMovementInput(Direction, ClampedAxis);
			bIncreasingCombatChance = true;
			GameInstance->ManageCombatChance();
		}
		else
		{
			bIncreasingCombatChance = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Null camera from PlayerController!"));
	}
}

void APlayerCharacterController::MoveRight(float Axis)
{
	if (MyCurrentCamera != nullptr)
	{
		if (Axis != 0.f)
		{
			float ClampedAxis = FMath::Clamp(Axis, -1.f, 1.f);
			FVector Direction = MyCurrentCamera->GetActorRightVector();
			ControlledCharacter->AddMovementInput(Direction, ClampedAxis);
			if (bIncreasingCombatChance == false)
			{
				bIncreasingCombatChance = true;
				GameInstance->ManageCombatChance();
			}
		}
		else if (bIncreasingCombatChance != true)
		{
			bIncreasingCombatChance = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Null camera from PlayerController!"))
	}
}