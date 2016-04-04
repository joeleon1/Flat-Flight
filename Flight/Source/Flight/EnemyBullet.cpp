// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightPlayer.h"
#include "EnemyBullet.h"


// Sets default values
AEnemyBullet::AEnemyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	ShipMesh->AttachTo(RootComponent);

	OnActorBeginOverlap.AddDynamic(this, &AEnemyBullet::onPlayerHit);
}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	timePassed += DeltaTime;

	if (timePassed >= deathTimer)
	{
		die();
	}
}

// Handles collision with player
void AEnemyBullet::onPlayerHit(AActor* otherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(otherActor);

	if (Player)
	{
		FDamageEvent Event;
		Player->TakeDamage(damage, Event, NULL, this);
		die();
	}
}

// Handles death 
void AEnemyBullet::die()
{
	Destroy();
}

// Sets an initial velocity to the bullet.
void AEnemyBullet::move()
{
	ShipMesh->ComponentVelocity = direction * speed;
}


