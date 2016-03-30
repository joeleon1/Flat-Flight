// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "enemyController.h"


// Sets default values
AenemyController::AenemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AenemyController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AenemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	move(DeltaTime);
}

