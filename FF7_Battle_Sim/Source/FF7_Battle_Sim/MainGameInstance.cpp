// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "Camera/CameraActor.h"
#include "EnemyInfoWidget.h"
#include "ActionMenuWidget.h"
#include "WorldMenuMainWidget.h"
#include "PlayerStatusWidget.h"

void UMainGameInstance::Init()
{
	Super::Init();

	GetWorld()->GetTimerManager().SetTimer(GameTimeCounter, this, &UMainGameInstance::CountUpPlayedTimer, 1.f, true, 0.f);
}

void UMainGameInstance::CountUpPlayedTimer()
{
	SecondsPlayedTwo += 1; //Count up single second.

	if (SecondsPlayedTwo > 9) // If the single second exceeds 9.
	{
		SecondsPlayedOne += 1; // Up tick 10 second.
		SecondsPlayedTwo = 0; // Reset the single second to 0.

		if (SecondsPlayedOne > 5) // If the 10 second exceeds 9.
		{
			MinutesPlayedTwo += 1; // Count up the single minute.
			SecondsPlayedOne = 0; // Reset the 10 second to 0.

			if (MinutesPlayedTwo > 9) // If the single minute exceeds 9.
			{
				MinutesPlayedOne += 1; // Count up the ten minute.
				MinutesPlayedTwo = 0; // Reset the single minute to 0.

				if (MinutesPlayedOne > 5) // If the 10 minute exceeds 9.
				{
					HoursPlayedTwo += 1; // Count up the single hour.
					MinutesPlayedOne = 0; // Reset the 10 minute to 0.

					if (HoursPlayedOne == 2 && HoursPlayedTwo == 4) // If the 10 hours is 2 and the single hours played is 4.
					{
						DaysPlayedFour += 1; // Count up the 4th days played digit.
						HoursPlayedTwo = 0; // Reset the 10 hours to 0.

						if (DaysPlayedFour > 9) // If days played 4th digit exceeds 9.
						{
							DaysPlayedThree += 1; // Count up the 3rd digit.
							DaysPlayedFour = 0; // Reset the 4th digit to 0.

							if (DaysPlayedThree > 9) // If the 3rd digit exceeds 9.
							{
								DaysPlayedTwo += 1; // Count up the 2nd digit.
								DaysPlayedThree = 0; // Reset the 3rd digit to 0.

								if (DaysPlayedTwo > 9) // If the 2nd digit exceeds 9.
								{
									DaysPlayedOne += 1; // Count up the first digit.
									DaysPlayedTwo = 0; // Reset the 2nd digit to 0.
								}
							}
						}
					}
					else // Unless we aren't ready to increase the day.
					{
						HoursPlayedOne += 1; // Count up the 10 hour.
						HoursPlayedTwo = 0; // Reset the hours played two to 0.
					}
				}	
			}
		}
	}
	if (WorldMainMenuWidget){WorldMainMenuWidget->UpdatePlayedTime(DaysPlayedOne, DaysPlayedTwo, DaysPlayedThree, DaysPlayedFour, HoursPlayedOne, HoursPlayedTwo, MinutesPlayedOne, MinutesPlayedTwo,  SecondsPlayedOne, SecondsPlayedTwo);}
}

void UMainGameInstance::CalculatePlayerExp(int32 inAwardedExp)
{
	MGI_StatMap.Emplace("CurrentExp") = *MGI_StatMap.Find("CurrentExp") + inAwardedExp;
	if (*MGI_StatMap.Find("CurrentExp") > *MGI_StatMap.Find("ExpToLevel"))
	{
		LevelUp();
	}
}

void UMainGameInstance::SetPlayerStatusWidget(UPlayerStatusWidget* inWidget)
{

}

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

void UMainGameInstance::SetWorldMenuMainWidget(UWorldMenuMainWidget* inWidget)
{
	WorldMainMenuWidget = inWidget;
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

	MGI_StatMap = ControlledCharacter->PC_StatMap;

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

void UMainGameInstance::LevelUp()
{
		MGI_StatMap.Emplace("Level") = *MGI_StatMap.Find("Level") + 1;
		MGI_StatMap.Emplace("CurrentExp") = *MGI_StatMap.Find("CurrentExp") - *MGI_StatMap.Find("ExpToLevel");
		MGI_StatMap.Emplace("ExpToLevel") = FMath::FloorToInt(float(*MGI_StatMap.Find("ExpToLevel")) + float((*MGI_StatMap.Find("ExpToLevel") / 10)));

		MGI_StatMap.Emplace("Strength") = MGI_StatMap.FindOrAdd("Strength") + FMath::RandRange(1, 2);
		MGI_StatMap.Emplace("Dexterity") = MGI_StatMap.FindOrAdd("Dexterity") + FMath::RandRange(1, 2);
		MGI_StatMap.Emplace("Vitality") = MGI_StatMap.FindOrAdd("Vitality") + FMath::RandRange(1, 2);
		MGI_StatMap.Emplace("Magic") = MGI_StatMap.FindOrAdd("Magic") + FMath::RandRange(1, 2);
		MGI_StatMap.Emplace("Spirit") = MGI_StatMap.FindOrAdd("Spirit") + FMath::RandRange(1, 2);
		MGI_StatMap.Emplace("Luck") = MGI_StatMap.FindOrAdd("Luck") + FMath::RandRange(1, 2);

		float LowestIncrease = float(*MGI_StatMap.Find("MaxHP") / 20);
		float HighestIncrease = float(*MGI_StatMap.Find("MaxHP") / 18);

		float RoughIncreaseAmount = FMath::RandRange(LowestIncrease, HighestIncrease);

		MGI_StatMap.Emplace("MaxHP") += FMath::FloorToInt(RoughIncreaseAmount);

		if (*MGI_StatMap.Find("CurrentExp") > *MGI_StatMap.Find("ExpToLevel"))
		{
			LevelUp();
		}
}