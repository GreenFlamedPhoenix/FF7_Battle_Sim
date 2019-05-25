// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatThemeMaps.h"
#include "Kismet/GameplayStatics.h"
#include "CombatGameMode.h"
#include "ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"

ACombatThemeMaps::ACombatThemeMaps()
{
	ConstructorHelpers::FObjectFinder<USoundCue> BattleMusicSoundCueObject(TEXT("SoundCue'/Game/Audio/Music/Battle/BattleSoundCue.BattleSoundCue'"));
	if (BattleMusicSoundCueObject.Succeeded())
	{
		BattleMusicSoundCue = BattleMusicSoundCueObject.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Someting went wrong with sound cue creation!"));
	}
}

void ACombatThemeMaps::BeginPlay()
{
	Super::BeginPlay();

	CombatGameMode = Cast<ACombatGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CombatGameMode == nullptr) {UE_LOG(LogTemp, Error, TEXT("Null GameMode from level!")) return;}

	UGameplayStatics::PlaySound2D(GetWorld(), BattleMusicSoundCue);
}

void ACombatThemeMaps::SetPlayerController()
{
	//CombatPlayerController = Cast<ACombatPlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	//if (CombatPlayerController == nullptr) { UE_LOG(LogTemp, Error, TEXT("Null PlayerController from level!")) return; }
}