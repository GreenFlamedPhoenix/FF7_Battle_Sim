// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "Camera/CameraActor.h"
#include "EnemyInfoWidget.h"
#include "ActionMenuWidget.h"

void UMainGameInstance::SetCharacterReference(APlayerCharacter* inPlayerCharacter)
{
	ControlledCharacter = inPlayerCharacter;
	if(ControlledCharacter == nullptr){UE_LOG(LogTemp,Error,TEXT("Null Character from GameInstance")) return;}
}

void UMainGameInstance::SetPlayerControllerReference(APlayerCharacterController* inPlayerController)
{
	CharacterController = inPlayerController;
	if(CharacterController == nullptr){UE_LOG(LogTemp,Error,TEXT("Null CharacterController from GameInstance"))return;}
}

/*Gets whether or not this is a combat map from the level*/
void UMainGameInstance::SetMapCombatState(bool bCombatMap)
{
	bCurrentlyInCombatMap = bCombatMap;
}

void UMainGameInstance::SetEnemyInfoWidget(UEnemyInfoWidget* Widget)
{
	EnemyInfoWidget = Widget;
}

void UMainGameInstance::SetActionMenuWidget(UActionMenuWidget* Widget)
{
	PlayerActionMenuWidget = Widget;
}

void UMainGameInstance::ManageCombatChance()
{
	if (bCurrentlyInCombatMap == true) //If we are in a map with combat.
	{
		CurrentCombatChance += .09f; //Increase the combat chance.

		if (CurrentCombatChance >= 25.f) //If our combat chance is at the minimum level (25% chance).
		{
			if (GetWorld()->GetTimerManager().IsTimerActive(RandomNumberCounter)) //If our random number counter is active.
			{
				if (CurrentCombatChance > CombatChanceRoll && CombatChanceRoll != 0.f) //If our CurrentCombatChance is greater than our random roll.
				{
					BeginCombat();
				}
				else
				{
					return;
				}
			}
			else
			{
				GetWorld()->GetTimerManager().SetTimer(RandomNumberCounter, this, &UMainGameInstance::GenerateRandomCombatRoll, true, 1.f);
			}
		}
	}
}

void UMainGameInstance::GenerateRandomCombatRoll()
{
	CombatChanceRoll = FMath::RandRange(25.f, 100.f);
}

void UMainGameInstance::BeginCombat()
{
	GetWorld()->GetTimerManager().ClearTimer(RandomNumberCounter);
	CurrentCombatChance = 0.f;
	CombatChanceRoll = 0.f;
	bCombatTriggered = true;

	SavedMapName = GetWorld()->GetMapName();
	if (SavedMapName.Contains(TEXT("S1_A1_Level")))
	{
		MapFName = "S1_A1_Level";
	}
	SavedCombatTransform = ControlledCharacter->GetActorTransform();
	SavedCameraName = CharacterController->MyCurrentCamera->GetName();
	CombatTriggered.Broadcast();
	MapTransitionEnum = EMapTransitionEnum::SpawnFromCombat;
}

void UMainGameInstance::CompleteCombat(FName SavedMapFName)
{
	UGameplayStatics::OpenLevel(this, SavedMapFName);
}