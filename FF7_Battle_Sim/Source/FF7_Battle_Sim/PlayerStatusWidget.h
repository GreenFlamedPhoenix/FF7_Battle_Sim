// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatusWidget.generated.h"
class AWorldMenuHUD;
class UMainGameInstance;
class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UPlayerStatusWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* StrengthStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DexterityStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* VitalityStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MagicStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SpiritStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* LuckStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ExitButton;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inHUD);

	UFUNCTION()
	void UpdateStats(int32 inStrength, int32 inDexterity, int32 inVitality, int32 inMagic, int32 inSpirit, int32 inLuck);

	UFUNCTION()
	void CloseMenu();
};
