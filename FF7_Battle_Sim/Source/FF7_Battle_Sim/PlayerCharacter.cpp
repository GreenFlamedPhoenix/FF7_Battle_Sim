// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "ConstructorHelpers.h"
#include "ATB_Component.h"
#include "WorldMenuHUD.h"
#include "PlayerStatusWidget.h"

APlayerCharacter::APlayerCharacter()
{
	 ConstructorHelpers::FObjectFinder<UTexture2D> PlayerIconObject(TEXT("Texture2D'/Game/ArtStuff/CharacterIcons/PlayerIcon.PlayerIcon'"));
	 if (PlayerIconObject.Succeeded()){PlayerIcon = PlayerIconObject.Object;}
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->SetCharacterReference(this);
	CharacterController->SetPlayerCharacter(this);
	SetStats();
	WorldMenuHUD = Cast<AWorldMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	
	WorldMenuHUD->PlayerStatusWidget->SetPlayerCharacter(this);

	PC_StatMap = GameInstance->MGI_StatMap;
	if (!PC_StatMap.Contains("CurrentHP"))
	{
		PC_StatMap.Add("Level", 1);
		PC_StatMap.Add("CurrentExp", 290);
		PC_StatMap.Add("ExpToLevel", 300);
		PC_StatMap.Add("CurrentHP", 140);
		PC_StatMap.Add("MaxHP", 140);
		PC_StatMap.Add("CurrentMP", 25);
		PC_StatMap.Add("MaxMP", 25);
		PC_StatMap.Add("Strength", 13);
		PC_StatMap.Add("Dexterity", 11);
		PC_StatMap.Add("Vitality", 10);
		PC_StatMap.Add("Magic", 8);
		PC_StatMap.Add("Spirit", 7);
		PC_StatMap.Add("Luck", 9);
	}
	WorldMenuHUD->PlayerStatusWidget->UpdateStats();
}

void APlayerCharacter::SetWorldMainMenuWidget(UWorldMenuMainWidget* inWidget)
{
	WorldMainMenuWidget = inWidget;
}

void APlayerCharacter::SetStats()
{
	PlayerStrength = GameInstance->GI_PlayerStrength;
	PlayerDexterity = GameInstance->GI_PlayerDexterity;
	PlayerVitality = GameInstance->GI_PlayerVitality;
	PlayerMagic = GameInstance->GI_PlayerMagic;
	PlayerSpirit = GameInstance->GI_PlayerSpirit;
	PlayerLuck = GameInstance->GI_PlayerLuck;
}