// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightBullet.h"


// Sets default values
AFlightBullet::AFlightBullet() :timeAlive(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->ProjectileGravityScale = 0;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	//Collider->SetEnableGravity(false);
	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	MovementComponent->InitialSpeed = 1000;
	MovementComponent->Friction = 0.0f;
	
	
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
