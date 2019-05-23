// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "MainGameInstance.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "WorldMapMode.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
	WorldMapGameMode = Cast<AWorldMapMode>(UGameplayStatics::GetGameMode(GetWorld()));
	WorldMapGameMode->SetWorldPlayerController(this);

	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if(GameInstance == nullptr){UE_LOG(LogTemp, Error, TEXT("Null GameInstance from Controller!"))};
}

/*Sets the ControlledCharacter once the character spawns.*/
void APlayerCharacterController::SetPlayerCharacter(APlayerCharacter* inPlayerCharacter)
{
	UE_LOG(LogTemp, Error, TEXT("Setting Character!"))
	ControlledCharacter = inPlayerCharacter;
	if(ControlledCharacter == nullptr){UE_LOG(LogTemp, Error, TEXT("Null Character from Controller!"))};
}

/*Function to be able to easily set the camera we are using for character movement.*/
void APlayerCharacterController::SetMapCamera(ACameraActor* MapCamera)
{
	UE_LOG(LogTemp, Error, TEXT("Setting Camera!"))
	MyCurrentCamera = MapCamera;
	if(MyCurrentCamera == nullptr){UE_LOG(LogTemp, Error, TEXT("Null Camera from Controller!"))};
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
	if (MyCurrentCamera != nullptr && ControlledCharacter != nullptr && GameInstance != nullptr)
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
		return;
	}
}

void APlayerCharacterController::MoveRight(float Axis)
{
	if (MyCurrentCamera != nullptr && ControlledCharacter != nullptr && GameInstance != nullptr)
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
		return;
	}
}