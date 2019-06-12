// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameInstance.h"
#include "ConstructorHelpers.h"

APlayerCharacter::APlayerCharacter()
{
	 ConstructorHelpers::FObjectFinder<UTexture2D> PlayerIconObject(TEXT("Texture2D'/Game/ArtStuff/CharacterIcons/PlayerIcon.PlayerIcon'"));
	 if (PlayerIconObject.Succeeded())
	 {
		 PlayerIcon = PlayerIconObject.Object;
	 }
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	

	CharacterController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	GameInstance->SetCharacterReference(this);
	CharacterController->SetPlayerCharacter(this);

}