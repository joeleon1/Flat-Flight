// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "EnemyDeath.h"


// Sets default values
AEnemyDeath::AEnemyDeath() :TimeTillDeath(5), TimeAlive(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SmokeParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Smoke Particle System"));
	SmokeParticleSystem->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyDeath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyDeath::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	TimeAlive += DeltaTime;

	if (TimeAlive >= TimeTillDeath)
	{
		Destroy();
	}
}

