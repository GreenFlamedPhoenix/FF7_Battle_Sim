// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionMenuWidget.generated.h"
class ACombatPlayerCharacterController;
class UMainGameInstance;
class ACombatHUD;

class UCanvasPanel;
class UImage;
class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UActionMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UActionMenuWidget(const FObjectInitializer& ObjectInitilizer);

	virtual void NativeOnInitialized() override;

	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	ACombatPlayerCharacterController* PlayerController;

	UFUNCTION()
	void SetWidgetVisibility(bool ReadyForAction);

	UFUNCTION()
	void AttackButtonClicked();

	UPROPERTY()
	bool bAttemptingAttack = false;

	UFUNCTION()
	float CalculateDamageDealt();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float DamageToDeal;

	UFUNCTION()
	void SetCombatHUD(ACombatHUD* inHUD);

	UPROPERTY()
	ACombatHUD* CombatHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* MainCanvas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* MenuCanvas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* BackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* AttackCommandText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MagicCommandText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemCommandText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* AttackCommandButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* MagicCommandButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ItemCommandButton;
};
