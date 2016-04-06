// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "EnemySpawner.h"


// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	timeToNextCheck -= DeltaTime;

	if (timeToNextCheck <= 0) {
		timeToNextCheck = spawnCheckRate;
		float temp = ((float)(rand() % 100)) / 100;

		if (temp < spawnChance) {

			SpawnEnemy();
		}


	}




}



void AEnemySpawner::SpawnEnemy() {
	//FActorSpawnParameters SpawnParameters;

	GetWorld()->SpawnActor<AenemyController>(EnemyClass,
		GetActorLocation(),
		GetActorRotation()
		);

}

