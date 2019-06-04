// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyInfoWidget.generated.h"
//class ACombatPlayerCharacterController;
class UMainGameInstance;

class UCanvasPanel;
class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UEnemyInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UEnemyInfoWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;

	//UPROPERTY()
	//ACombatPlayerCharacterController* CombatController;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	bool bCurrentlyOverEnemy = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* MainCanvas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* CanvasBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EnemyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EnemyCurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EnemyMaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EnemyCurrentMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* EnemyMaxMP;

	UFUNCTION(BlueprintCallable)
	void SetWidgetVisibility(bool HoveringOverEnemy);

	void SetEnemyName(FString inEnemyName);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> EnemyClass;

	void SetEnemyCurrentHP(int32 CurrentHP);

	void SetEnemyMaxHP(int32 MaxHP);

	void SetEnemyCurrentMP(int32 CurrentMP);

	void SetEnemyMaxMP(int32 MaxMP);
};