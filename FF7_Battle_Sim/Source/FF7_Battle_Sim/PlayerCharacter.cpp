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
	WorldMenuHUD->PlayerStatusWidget->UpdateStats(PlayerStrength, PlayerDexterity, PlayerVitality, PlayerMagic, PlayerSpirit, PlayerLuck);
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