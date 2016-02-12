// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightPowerUp.h"
#include "../PlayerShip.h"

// Sets default values
AFlightPowerUp::AFlightPowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	OnActorBeginOverlap.AddDynamic(this, &AFlightPowerUp::OnBeginOverlap);
}


