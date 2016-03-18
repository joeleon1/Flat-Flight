// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightPowerUp.h"
#include "../PlayerShip.h"

// Sets default values
AFlightPowerUp::AFlightPowerUp():TimeAlive(10),TimeSinceSpawn(0)
{
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);
}


void AFlightPowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceSpawn += DeltaTime;
	if (TimeSinceSpawn >= TimeAlive)
		Destroy();
}

