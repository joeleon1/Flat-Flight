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
		numOfLoops++;

		if (numOfLoops >= timesToIncreaseDifficulty) {
			numOfLoops = 0;
			speedToAssign += speedIncrease;
		}

		float temp = ((float)(rand() % 100)) / 100.0f;

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Checking for spawn: "+ FString::SanitizeFloat(temp));

		if (temp <= spawnChance) {

			SpawnEnemy();
		}

	}


}



void AEnemySpawner::SpawnEnemy() {
	//FActorSpawnParameters SpawnParameters;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Spawning enemy");
	AenemyController* newEnemy;

	newEnemy =  GetWorld()->SpawnActor<AenemyController>(EnemyClass,
		this->GetActorLocation(),
		this->GetActorRotation()
		);
	newEnemy->downSpeed = speedToAssign;
}

