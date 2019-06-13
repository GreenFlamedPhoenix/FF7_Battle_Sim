// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SaveMenuWidget.generated.h"
class AWorldMenuHUD;
class UButton;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API USaveMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY()
	AWorldMenuHUD* WorldMenuHUD;

	UFUNCTION()
	void SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* SaveSlot1;

	UFUNCTION()
	void SaveToSlot1();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWIdget))
	UButton* SaveSlot2;

	UFUNCTION()
	void SaveToSlot2();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWIdget))
	UButton* SaveSlot3;

	UFUNCTION()
	void SaveToSlot3();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWIdget))
	UButton* SaveSlot4;

	UFUNCTION()
	void SaveToSlot4();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWIdget))
	UButton* SaveSlot5;

	UFUNCTION()
	void SaveToSlot5();
};
