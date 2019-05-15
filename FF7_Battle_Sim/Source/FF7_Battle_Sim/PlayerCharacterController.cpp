// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "CombatTrackingComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	/*Find the character we are controlling*/
	ControlledCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (ControlledCharacter == nullptr) {UE_LOG(LogTemp, Error, TEXT("ControlledCharacter from controlled is null!")); return;}

	/*Find the CombatTrackingComponent for our character*/
	CombatTrackingComponent = ControlledCharacter->FindComponentByClass<UCombatTrackingComponent>();
	if (CombatTrackingComponent == nullptr) {UE_LOG(LogTemp, Error, TEXT("CombatTrackingComponent from controlled is null!")); return;}
}

/*Function to be able to easily set the camera we are using*/
void APlayerCharacterController::SetMapCamera(ACameraActor* MapCamera)
{
	MyCurrentCamera = MapCamera;
	UE_LOG(LogTemp, Warning, TEXT("Camera set to %s"), *MyCurrentCamera->GetFullName());
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
			CombatTrackingComponent->ManageCombatChance();
		}
		else
		{
			bIncreasingCombatChance = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Camera null for PlayerController."));
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
				CombatTrackingComponent->ManageCombatChance();
			}
		}
		else if (bIncreasingCombatChance != true)
		{
			bIncreasingCombatChance = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Camera null for PlayerController."))
	}
}