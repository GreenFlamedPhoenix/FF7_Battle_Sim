// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WorldMenuMainWidget.generated.h"
class AMasterWorldMap;
class AWorldMenuHUD;
class APlayerCharacter;
class UMainGameInstance;
class UTextBlock;
class UImage;
class UProgressBar;
class UButton;

/**
 *
 */
UCLASS()
class FF7_BATTLE_SIM_API UWorldMenuMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void FindMyCharacter();

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	AWorldMenuHUD* WorldMenuHUD;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD);

	UPROPERTY()
	FTimerHandle SearchCharacterTimer;

	UPROPERTY()
	AMasterWorldMap* MasterWorldMap;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* LocationNameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* PlayerIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MaxMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* CharacterOneHP_ProgressBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* CharacterOneMP_ProgressBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SaveText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* SaveButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DaysPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HoursPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MinutesPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SecondsPlayed;


	UFUNCTION(BlueprintCallable)
	void SetPlayerIcon();

	UFUNCTION(BlueprintCallable)
	void SetLocationNameText(FString inLevelName);

	UFUNCTION()
	void SetCharacterOneStats(int32 inCurrentHP, int32 inMaxHP, int32 inCurrentMP, int32 inMaxMP);

	UFUNCTION(BlueprintCallable)
	void SetSaveEnabled(bool inbAbleToSave);

	UFUNCTION()
	void OpenSaveScreen();

	UFUNCTION()
	void UpdatePlayedTime(int32 inDays, int32 inHours, int32 inMinutes, int32 inSeconds);
};
