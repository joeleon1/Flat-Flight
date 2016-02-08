// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightBullet.h"


// Sets default values
AFlightBullet::AFlightBullet() :timeAlive(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	
}


void AFlightBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeAlive += DeltaTime;
	if (timeAlive > TimeTillDeath)
	{
		Destroy();
	}
}
