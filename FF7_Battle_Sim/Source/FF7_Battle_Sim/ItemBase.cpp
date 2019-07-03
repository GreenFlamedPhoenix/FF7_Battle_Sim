// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "CombatHUD.h"

// Sets default values
AItemBase::AItemBase()
{;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AItemBase::UseItem()
{
	MainGameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
	CombatHUD = Cast<ACombatHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	CombatCharacter = Cast<ACombatPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}