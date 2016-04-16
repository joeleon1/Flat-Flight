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

			SpawnBoss();
		}
	}
}

void ABossSpawner::SpawnBoss() {
	//FActorSpawnParameters SpawnParameters;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Spawning enemy");
	ARealBoss* newBoss;

	newBoss = GetWorld()->SpawnActor<ARealBoss>(BossClass,
		this->GetActorLocation(),
		this->GetActorRotation()
		);
	newBoss->horizontalSpeed = speedToAssign;
}

