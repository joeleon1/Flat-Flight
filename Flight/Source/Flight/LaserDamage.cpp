// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LaserDamage.h"


// Sets default values
ALaserDamage::ALaserDamage():TimeTillDeath(5),TimeAlive(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LaserParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Laser Particle System"));
	LaserParticleSystem->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ALaserDamage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserDamage::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	TimeAlive += DeltaTime;
	if (GetOwner())
	{
		SetActorLocation(GetOwner()->GetActorLocation());
	}
	else 
	{
		Destroy(); 
	}

	if (TimeAlive >= TimeTillDeath)
	{
		Destroy();
	}
}

