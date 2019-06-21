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
class UCanvasPanel;

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
	UTextBlock* DaysPlayedOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DaysPlayedTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DaysPlayedThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DaysPlayedFour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HoursPlayedOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HoursPlayedTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MinutesPlayedOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MinutesPlayedTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SecondsPlayedOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SecondsPlayedTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PlayerOneCurrentExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PlayerOneExpToLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* PlayerOneLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* PlayerOneExpBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* StatusButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ConfirmQuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* CancelQuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* ConfirmQuitCanvas;


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
	void UpdatePlayedTime(int32 inDaysOne, int32 inDaysTwo, int32 inDaysThree, int32 inDaysFour, int32 inHoursOne, int32 inHoursTwo, int32 inMinutesOne, int32 inMinutesTwo, int32 inSecondsOne, int32 inSecondsTwo);

	UFUNCTION()
	void SetPlayerOneExp();

	UFUNCTION()
	void SetPlayerOneLevel();

	UFUNCTION()
	void SetPlayerOneExpBar();

	UFUNCTION()
	void OpenStatusMenu();

	UFUNCTION()
	void SetHP_MP_Bars();

	UFUNCTION()
	void MenuOpened();

	UFUNCTION()
	void OpenConfirmQuit();

	UFUNCTION()
	void ConfirmQuitGame();

	UFUNCTION()
	void CancelQuitGame();
};
