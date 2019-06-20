// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OpeningMenuWidget.generated.h"
class AOpeningMenuHUD;
class UButton;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UOpeningMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AOpeningMenuHUD* OpeningMenuHUD;

	UFUNCTION()
	void SetOpeningMenuHUD(AOpeningMenuHUD* inHUD);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ContinueButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitButton;

	UFUNCTION()
	void ContinueButtonClicked();

	UFUNCTION()
	void QuitButtonClicked();
	
};
