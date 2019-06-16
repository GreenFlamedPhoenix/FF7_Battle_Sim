// Fill out your copyright notice in the Description page of Project Settings.


#include "ATB_Component.h"
#include "CombatPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CombatPlayerCharacterController.h"
#include "ActionMenuWidget.h"

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
	FString Owner = this->GetOwner()->GetName();
	ATB_FillSpeed = ((inDexterity+200)*.001f/inStatusMultiplier);
	UE_LOG(LogTemp, Warning, TEXT("%s Speed: %f"), *Owner, ATB_FillSpeed);
}

void UATB_Component::DetermineATB_InitialFill(bool bIsPlayer)
{
	if (bIsPlayer == true) { bOwnedByPlayer = true; CurrentATB_Fill = 0.f; CurrentATB_Fill = FMath::RandRange(25.f, 75.f);}
	else{bOwnedByPlayer = false; CurrentATB_Fill = 0.f;}
}

void UATB_Component::TickATB_Delay()
{
	DelayTimer += 1;

	if(DelayTimer == 3)
	{
		GetWorld()->GetTimerManager().SetTimer(ATB_FillTimer, this, &UATB_Component::TickUpATB, .01f, true, 0);
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
		GetWorld()->GetTimerManager().PauseTimer(ATB_FillTimer);
		DisplayActionenuWidget();
	}
}

void UATB_Component::ResetATB()
{
	bOwnerActionReady = false;
	CurrentATB_Fill = 0.f;
	GetWorld()->GetTimerManager().UnPauseTimer(ATB_FillTimer);
}

void UATB_Component::DisplayActionenuWidget()
{
	if (bOwnedByPlayer == true)
	{
		class ACombatPlayerCharacterController* CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		if (CombatController)
		{
			CombatController->ActionMenuWidget->SetWidgetVisibility(true);
		}
	}
}