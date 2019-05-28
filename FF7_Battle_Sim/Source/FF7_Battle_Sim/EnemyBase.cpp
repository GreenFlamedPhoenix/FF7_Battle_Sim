// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CombatPlayerCharacterController.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("My Root Component"));
	RootComponent = MyRootComponent;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SkeletalMesh->SetupAttachment(RootComponent);
	//SkeletalMesh->AddLocalRotation(FRotator(0.f, 0.f, 90.f));
	SkeletalMesh->OnBeginCursorOver.AddDynamic(this, &AEnemyBase::StartCursorHover);
	SkeletalMesh->OnEndCursorOver.AddDynamic(this, &AEnemyBase::EndCursorHover);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	CombatController = Cast<ACombatPlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBase::StartCursorHover(UPrimitiveComponent* TouchComponent)
{
	FHitResult ActorHit;
	CombatController->bHoveringEnemy = true;
	CombatController->GetHitResultUnderCursor(ECC_WorldStatic, true, ActorHit);
	CombatController->HoveredActor = ActorHit.GetActor();
}

void AEnemyBase::EndCursorHover(UPrimitiveComponent* TouchComponent)
{
	CombatController->bHoveringEnemy = false;
}