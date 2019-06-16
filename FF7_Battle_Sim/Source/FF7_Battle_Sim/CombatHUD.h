// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <Runtime/UMG/Public/Components/WidgetComponent.h>
#include "CombatStatusWidget.h"
#include "EnemyInfoWidget.h"
#include "ActionMenuWidget.h"
#include "CombatHUD.generated.h"
class UCombatStatusWidget;
class UEnemyInfoWidget;
class UActionMenuWidget;
class ACombatPlayerCharacter;
class UATB_Component;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API ACombatHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void DrawHUD() override;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> CombatStatusWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> EnemyInfoWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> ActionMenuWidgetClass;

	UPROPERTY()
	UCombatStatusWidget* CombatStatusWidget;

	UPROPERTY()
	UEnemyInfoWidget* EnemyInfoWidget;

	UPROPERTY()
	UActionMenuWidget* ActionMenuWidget;

	UFUNCTION()
	void CreateCombatStatusWidget();

	UFUNCTION()
	void CreateEnemyInfoWidget();
	
	UFUNCTION()
	void CreateActionMenuWidget();

	UPROPERTY()
	ACombatPlayerCharacter* CombatPlayerCharacter;

	UPROPERTY()
	FTimerHandle ReferenceSearchTimer;

	UFUNCTION()
	void SearchForReferences();

	UPROPERTY()
	UATB_Component* ATB_Component;

	UFUNCTION()
	void SetPlayerCharacter(ACombatPlayerCharacter* inCharacter);

	UFUNCTION()
	void SetATB_Component(UATB_Component* inComponent);

	UPROPERTY()
	bool bReferencesReady;
};