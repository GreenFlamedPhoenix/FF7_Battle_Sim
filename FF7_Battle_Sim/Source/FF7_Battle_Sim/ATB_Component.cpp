// Fill out your copyright notice in the Description page of Project Settings.


#include "ATB_Component.h"

// Sets default values for this component's properties
UATB_Component::UATB_Component()
{

}

// Called when the game starts
void UATB_Component::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(ATB_DelayTimer, this, &UATB_Component::TickATB_Delay, 1.f, true, 0);
}

void UATB_Component::CalculateATB_FillSpeed(int32 inDexterity, int32 inStatusMultiplier)
{
	ATB_FillSpeed = inDexterity / 3 + 375 * .6f * inStatusMultiplier;
	//UE_LOG(LogTemp, Warning, TEXT("My fill %f"), ATB_FillSpeed)
}

void UATB_Component::DetermineATB_InitialFill(bool bIsPlayer)
{
	if(bIsPlayer == true){CurrentATB_Fill = FMath::RandRange(750.f, 900.f);}
	else{CurrentATB_Fill = 0.f;}
}

void UATB_Component::TickATB_Delay()
{
	DelayTimer += 1;

	if(DelayTimer == 5)
	{
		GetWorld()->GetTimerManager().SetTimer(ATB_FilTimer, this, &UATB_Component::TickUpATB, .1f, true, 0);
		GetWorld()->GetTimerManager().ClearTimer(ATB_DelayTimer);
	}
}

void UATB_Component::TickUpATB()
{
	if(CurrentATB_Fill < MaxATB_Fill){CurrentATB_Fill += ATB_FillSpeed;}
	else
	{
		bOwnerActionReady = true; 
		ATB_Full.Broadcast();
		GetWorld()->GetTimerManager().PauseTimer(ATB_FilTimer);
	}
}