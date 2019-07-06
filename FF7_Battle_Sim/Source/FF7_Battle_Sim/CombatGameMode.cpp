// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatGameMode.h"
#include "MainGameInstance.h"
#include "CombatPlayerCharacter.h"

void ACombatGameMode::BeginPlay()
{
	Super::BeginPlay();

	bCombatStopped = false;
	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
}

void ACombatGameMode::SetCombatCharacter(ACombatPlayerCharacter* inCombatPlayerCharacter)
{
	CombatPlayerCharacter = inCombatPlayerCharacter;
}

void ACombatGameMode::SetupEnemyAttributes(int32 AmountChange, int32 inExp)
{
	CurrentEnemies = CurrentEnemies + AmountChange;
	ExpToAward += inExp;

	if (CurrentEnemies == 0)
	{
		CombatPlayerCharacter->bCombatFinished = true;
		GetWorldTimerManager().SetTimer(CloseCombatTimer, this, &ACombatGameMode::CountDownCombatCounter, 1.f, true, 0.f);
		AwardPlayerExp(ExpToAward);
		MainGameInstance->MGI_StatMap = CombatPlayerCharacter->CPC_StatMap;
	}
}

void ACombatGameMode::ManagePlayerCounts(int32 AmountChange)
{
	CurrentPlayersAlive += AmountChange;

	if (CurrentPlayersAlive <= 0)
	{
		bCombatStopped = true;
		bIsGameOver = true;
		LeaveCombatEvent.Broadcast();
	}
}

void ACombatGameMode::CountDownCombatCounter()
{
	if (CombatCloseCounter > 0)
	{
		CombatCloseCounter -= 1;
	}
	else
	{
		CombatPlayerCharacter->bCombatFinished = false;
		MainGameInstance->CompleteCombat();
	}
}

void ACombatGameMode::AwardPlayerExp(int32 inExpAwarded)
{
	UE_LOG(LogTemp, Warning, TEXT("Awarding %i exp to player!"), inExpAwarded)

	CombatPlayerCharacter->CPC_StatMap.Emplace("CurrentExp") = *CombatPlayerCharacter->CPC_StatMap.Find("CurrentExp") + inExpAwarded;

	UE_LOG(LogTemp, Warning, TEXT("New current exp is %i"), *MainGameInstance->MGI_StatMap.Find("CurrentExp"))

		if (*CombatPlayerCharacter->CPC_StatMap.Find("CurrentExp") >= *CombatPlayerCharacter->CPC_StatMap.Find("ExpToLevel"))
		{
			LevelUpCharacter();
		}
}

void ACombatGameMode::LevelUpCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("Leveling up!"))

	CombatPlayerCharacter->CPC_StatMap.Emplace("Level") = *CombatPlayerCharacter->CPC_StatMap.Find("Level") + 1;
	CombatPlayerCharacter->CPC_StatMap.Emplace("CurrentExp") = *CombatPlayerCharacter->CPC_StatMap.Find("CurrentExp") - *CombatPlayerCharacter->CPC_StatMap.Find("ExpToLevel");
	CombatPlayerCharacter->CPC_StatMap.Emplace("ExpToLevel") = FMath::FloorToInt(float(*CombatPlayerCharacter->CPC_StatMap.Find("ExpToLevel")) + float((*CombatPlayerCharacter->CPC_StatMap.Find("ExpToLevel") / 10)));

	CombatPlayerCharacter->CPC_StatMap.Emplace("Strength") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Strength") + FMath::RandRange(1, 2);
	CombatPlayerCharacter->CPC_StatMap.Emplace("Dexterity") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Dexterity") + FMath::RandRange(1, 2);
	CombatPlayerCharacter->CPC_StatMap.Emplace("Vitality") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Vitality") + FMath::RandRange(1, 2);
	CombatPlayerCharacter->CPC_StatMap.Emplace("Magic") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Magic") + FMath::RandRange(1, 2);
	CombatPlayerCharacter->CPC_StatMap.Emplace("Spirit") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Spirit") + FMath::RandRange(1, 2);
	CombatPlayerCharacter->CPC_StatMap.Emplace("Luck") = CombatPlayerCharacter->CPC_StatMap.FindOrAdd("Luck") + FMath::RandRange(1, 2);

	float LowestIncrease = float(*CombatPlayerCharacter->CPC_StatMap.Find("MaxHP") / 18);
	float HighestIncrease = float(*CombatPlayerCharacter->CPC_StatMap.Find("MaxHP") / 15);

	float RoughIncreaseAmount = FMath::RandRange(LowestIncrease, HighestIncrease);

	CombatPlayerCharacter->CPC_StatMap.Emplace("MaxHP") = *CombatPlayerCharacter->CPC_StatMap.Find("MaxHP") + FMath::FloorToInt(RoughIncreaseAmount);

	if (*CombatPlayerCharacter->CPC_StatMap.Find("CurrentExp") > *CombatPlayerCharacter->CPC_StatMap.Find("ExpToLevel"))
	{
		LevelUpCharacter();
	}
}
