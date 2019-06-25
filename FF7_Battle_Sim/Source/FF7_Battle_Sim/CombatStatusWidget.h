// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime\UMG\Public\UMG.h"
#include "CombatStatusWidget.generated.h"
class ACombatHUD;
class ACombatPlayerCharacter;
class UATB_Component;
class ACombatHUD;

class UCanvasPanel;
class UTextBlock;
class UProgressBar;
class UImage;

/**
 * 
 */
UCLASS()
class FF7_BATTLE_SIM_API UCombatStatusWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCombatStatusWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACombatPlayerCharacter* CombatCharacter;

	UPROPERTY()
	UATB_Component* ATB_Component;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void ManageHP();

	UFUNCTION()
	void ManageMP();

	UFUNCTION(BlueprintCallable)
	void ATB_TimeBarFill();

	UFUNCTION(BlueprintCallable)
	FLinearColor ATB_TimeBarTint();

	UFUNCTION()
	void SetHUD_Reference(ACombatHUD* inHUD);

	UPROPERTY()
	ACombatHUD* CombatHUD;

	//*The decorative pieces of our widget.
	//The main canvas panel that holds everything else.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* StatusPanel;

	//Background image of our canvas.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* CanvasBackground;

	//* <-- Labels. -->
	//Label for character names.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterNameLabel;

	//Label for barrier area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* BarrierLabel;

	//Label for the HP area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* HP_Label;

	//Label for the MP area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* MP_Label;

	//Label for the Limit area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* LimitLabel;

	//Label for the ATB area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ATB_Label;


	//* <-- Character name stuff. -->
	//Character name text.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterName;


	//* <-- Barrier stuff. -->
	//Progress bar for our Barrier charge.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* BarrierBar;

	//Progress bar for our MBarrier charge.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* M_BarrierBar;

	//Background image for barrier bars.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* BarrierBackground;


	//* <-- *HP stuff. -->
	//Characters current HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterCurrentHP;

	//Characters Max HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterMaxHP;

	//Progress bar for HP remaining.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HP_ProgressBar;


	//* <-- MP Stuff. -->
	//Characters current MP.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterCurrentMP;

	//Characters Max MP.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CharacterMaxMP;

	//Progress bar for MP remaining.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* MP_ProgressBar;


	//* <-- Limit stuff. -->
	//Progress bar for our limit break.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* LimitBar;


	//* <-- ATB Stuff -->
	//Background image for ATB bar.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* ATB_Background;

	//Progress bar for our ATB
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ATB_Bar;
};