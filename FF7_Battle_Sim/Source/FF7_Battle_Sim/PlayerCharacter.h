// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "PlayerCharacter.generated.h"
class APlayerCharacterController;
class UMainGameInstance;
class UTexture2D;
class UWorldMenuMainWidget;
class UATB_Component;
class AWorldMenuHUD;

UCLASS()
class FF7_BATTLE_SIM_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	

	virtual void BeginPlay() override;
	
	UPROPERTY()
	APlayerCharacterController* CharacterController;

	UPROPERTY()
	UMainGameInstance* GameInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTexture2D* PlayerIcon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWorldMenuMainWidget* WorldMainMenuWidget;

	UFUNCTION()
	void SetWorldMainMenuWidget(UWorldMenuMainWidget* inWidget);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bAbleToSave;

	UPROPERTY()
	int32 PlayerStrength = 1;

	UPROPERTY()
	int32 PlayerDexterity = 1;

	UPROPERTY()
	int32 PlayerVitality = 1;

	UPROPERTY()
	int32 PlayerMagic = 1;

	UPROPERTY()
	int32 PlayerSpirit = 1;

	UPROPERTY()
	int32 PlayerLuck = 1;

	UFUNCTION()
	void SetStats();

	UPROPERTY()
	AWorldMenuHUD* WorldMenuHUD;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FString, int32> PC_StatMap;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName SavingMapName;
};
