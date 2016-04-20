// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlatEarth.h"


// Sets default values
AFlatEarth::AFlatEarth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshOne = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshOne"));
	MeshTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshTwo"));
	MeshOne->AttachTo(RootComponent);
	MeshTwo->AttachTo(MeshOne);
}

// Called when the game starts or when spawned
void AFlatEarth::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation().Y;
	
}

// Called every frame
void AFlatEarth::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector Position = GetActorLocation();
	Position.Y -= 10;
	if (Position.Y == SwapPosition)
	{
		Position.Y = StartPosition;
	}
	SetActorLocation(Position);
	
}

