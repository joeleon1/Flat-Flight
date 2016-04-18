// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BossSpawner.h"


// Sets default values
ABossSpawner::ABossSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABossSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABossSpawner::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

	gameTime += DeltaTime;

	if (isBossSpawned == false && gameTime > timeToSpawnBoss) {
		isBossSpawned = true;
		//int temp = (rand() % ((int)maxHeight - (int)minHeight)) + minHeight;
		SpawnBoss();
	}
}

void ABossSpawner::SpawnBoss() {
	//FActorSpawnParameters SpawnParameters;
	ARealBoss* newBoss;

	newBoss = GetWorld()->SpawnActor<ARealBoss>(BossClass,
		this->GetActorLocation(),
		this->GetActorRotation()
		);
	newBoss->horizontalSpeed = speedToAssign;
}

