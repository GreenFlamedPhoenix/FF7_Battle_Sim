// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>("Character Camera SpringArm");
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 50.f), FRotator(-60.f, 0.f, 100.f));

	UCameraComponent* PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	PlayerCamera->AttachTo(SpringArm);

	CombatTrackingComponent = CreateDefaultSubobject<UCombatTrackingComponent>("Combat Tracking Component");

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

