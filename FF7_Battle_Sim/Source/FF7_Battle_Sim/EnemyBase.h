
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"
class UMainGameInstance;
class ACombatPlayerCharacterController;
class UEnemyInfoWidget;
class UActionMenuWidget;



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

	//Used by children of the EnemyBase. Reference for the actor we are hovering to get access to its name and stats.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* HoveredActor;
};