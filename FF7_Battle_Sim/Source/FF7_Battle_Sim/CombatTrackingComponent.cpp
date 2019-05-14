// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTrackingComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCombatTrackingComponent::UCombatTrackingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UCombatTrackingComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCombatTrackingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCombatTrackingComponent::SetMapCombatState(bool bCombatMap)
{
	bCurrentlyInCombatMap = bCombatMap;
}

void UCombatTrackingComponent::ManageCombatChance()
{
	if (bCurrentlyInCombatMap == true)
	{
		CurrentCombatChance += .1f;
		
		if (CurrentCombatChance >= 25.f)
		{
			if (GetWorld()->GetTimerManager().IsTimerActive(RandomNumberCounter))
			{
				if (CurrentCombatChance > RandomCombatNumber && RandomCombatNumber != 0.f)
				{
					UE_LOG(LogTemp, Warning, TEXT("Entered combat!"));
					GetWorld()->GetTimerManager().ClearTimer(RandomNumberCounter);
					CurrentCombatChance = 0.f;
					RandomCombatNumber = 0.f;
				}
				else
				{
					return;
				}
			}
			else
			{
				GetWorld()->GetTimerManager().SetTimer(RandomNumberCounter, this, &UCombatTrackingComponent::GenerateRandomCombatRoll, true, 1.f);
			}
		}
	}
}

void UCombatTrackingComponent::GenerateRandomCombatRoll()
{
	RandomCombatNumber = FMath::RandRange(25.f, 100.f);
}