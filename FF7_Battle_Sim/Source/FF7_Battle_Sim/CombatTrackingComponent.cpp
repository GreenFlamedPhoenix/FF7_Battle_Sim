// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTrackingComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCombatTrackingComponent::UCombatTrackingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCombatTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	//CurrentLevel = Cast<ULevel>(GetWorld()->GetLevel(0));
	//if (CurrentLevel == nullptr) { UE_LOG(LogTemp, Error, TEXT("Current level is null.")); return; }
}


// Called every frame
void UCombatTrackingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bCurrentlyInCombatMap == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("We are in a combat map! Careful!"));
	}
	else if (bCurrentlyInCombatMap == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("We are safe here!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Something went wrong determining map combat state!"));
	}
}

void UCombatTrackingComponent::SetMapCombatState(bool bCombatMap)
{
	bCurrentlyInCombatMap = bCombatMap;
}