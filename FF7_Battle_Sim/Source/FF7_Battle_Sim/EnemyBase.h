
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"
class UMainGameInstance;
class ACombatPlayerCharacterController;
class UEnemyInfoWidget;
class UActionMenuWidget;
class ACombatGameMode;
class ACombatPlayerCharacter;
class UATB_Component;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageTakenNumber, int32, DamageTaken);

UCLASS()
class FF7_BATTLE_SIM_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//////////////////////////////
	//	Base References.
	//	References for the various classes the EnemyBase needs to communicate with.
	//////////////////////////////

	// Characters capsule component. Also used by all children of this class. Used for mouse hovering and clicking events.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CharacterCapsule;

	//Reference for our combat player controller. Also used by all children of this class.
	UPROPERTY()
	ACombatPlayerCharacterController* CombatController;

	//Reference to the EnemyInfoWidget. Updating the displayed enemy name and stats of the widget.
	UPROPERTY()
	UEnemyInfoWidget* EnemysEnemyInfoWidget;

	//Reference for the ActionMenuWidget. Used to interact with the "Attack" command. May be removed at some point.
	UPROPERTY()
	UActionMenuWidget* ActionMenuWidget;

	//Reference for the MainGameInstance. Used to get the widget references once Enemy spawns.
	UPROPERTY()
	UMainGameInstance* MainGameInstance;

	UPROPERTY()
	ACombatGameMode* CombatGameMode;

	//Our character. Testing usage with moving to enemies and attacking animations.
	UPROPERTY()
	ACombatPlayerCharacter* EnemiesCombatCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UATB_Component* Enemy_ATB_Component;

	//////////////////////////////
	//	Enemy interactions.
	//	Holds variables for actions involving hovering and clicking on the actors.
	//////////////////////////////

	//Functions for when starting and ending our hover over an enemy. Used by children of this class.
	UFUNCTION()
	virtual void StartCursorHover(UPrimitiveComponent* TouchComponent);
	UFUNCTION()
	virtual void EndCursorHover(UPrimitiveComponent* TouchComponent);

	//Function that triggers when clicking on an actor. Used by children of this class
	UFUNCTION()
	virtual void ActorBeingTargetted(UPrimitiveComponent* TouchComponent, FKey inKey);

	UFUNCTION(BlueprintCallable)
	virtual void Attack();

	//Used by children of the EnemyBase. Reference for the actor we are hovering to get access to its name and stats.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* HoveredActor;

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeathEvent;

	UPROPERTY(BlueprintAssignable)
	FOnDamage OnDamageEvent;

	UPROPERTY(BlueprintAssignable)
	FDamageTakenNumber DamageTakenNumberEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyCurrentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyMaxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyCurrentMP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyMaxMP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyDexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyVitality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyLuck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Stats")
	int32 EnemyExpWorth;
};