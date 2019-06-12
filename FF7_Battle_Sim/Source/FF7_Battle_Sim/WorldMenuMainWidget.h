// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WorldMenuMainWidget.generated.h"
class AMasterWorldMap;
class APlayerCharacter;
class UTextBlock;
class UImage;
class UProgressBar;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UWorldMenuMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	//UPROPERTY()
	//FTimerHandle SearchMapTimer;

	//UFUNCTION()
	//void FindMyMap();

	UFUNCTION()
	void FindMyCharacter();

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

	UFUNCTION(BlueprintCallable)
	void SetPlayerIcon();

	UFUNCTION(BlueprintCallable)
	void SetLocationNameText(FString inLevelName);

	void SetCharacterOneStats(int32 inCurrentHP, int32 inMaxHP, int32 inCurrentMP, int32 inMaxMP);
	
};
