// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatPlayerCharacter.h"
#include "CombatInterface.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"
#include "ATB_Component.h"
#include "CombatHUD.h"
#include "MainGameInstance.h"

ACombatPlayerCharacter::ACombatPlayerCharacter()
{
	ATB_Component = CreateDefaultSubobject<UATB_Component>(TEXT("ATB_Component"));
	if (ATB_Component){ATB_Component->ATB_Full.AddDynamic(this, &ACombatPlayerCharacter::ReadyForAction);}
}

// Called when the game starts or when spawned
void ACombatPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	CombatGameMode->SetCombatCharacter(this);
	if (ATB_Component) {ATB_Component->DetermineATB_InitialFill(true); ATB_Component->CalculateATB_FillSpeed(Dexterity, 1);}
	CombatHUD = Cast<ACombatHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	CPC_StatMap = MainGameInstance->MGI_StatMap;
	if (CombatHUD)
	{
		CombatHUD->SetPlayerCharacter(this);
		CombatHUD->SetATB_Component(ATB_Component);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No HUD!"))
	}
}


void ACombatPlayerCharacter::PlayerTakeDamage(float inDamage)
{
	float DamageReductionPercentage = (float(*CPC_StatMap.Find("Vitality")) * 5) / 1700;
	float DamageToMitigate = inDamage * DamageReductionPercentage;
	int32 FinalDamageTaken = FMath::FloorToInt(inDamage - DamageToMitigate);

	CPC_StatMap.Emplace("CurrentHP") = (*CPC_StatMap.Find("CurrentHP") - FinalDamageTaken);

	if (CPC_StatMap.Find("CurrentHP") <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game over!"));
	}
}

void ACombatPlayerCharacter::ReadyForAction()
{
	
}