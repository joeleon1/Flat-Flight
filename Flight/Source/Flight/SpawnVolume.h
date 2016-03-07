// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"
//change this define if you need the spawner to hold more items 
#define SPAWNER_ARRAY_SIZE 10
UCLASS()


/*This class is created as a blue print and placed in the world you can set when it will start and how often it will spawn and will only spawn an actor when the previous one is destroyed
All of these variables are set through the properties inspector in engine
*/
class FLIGHT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//BoxComponent to specify the spawning area within the level
	UPROPERTY(VisibleAnywhere, Category = Spawning)
		UBoxComponent* WhereToSpawn;

	//The pickup to spawn 
	UPROPERTY(EditAnywhere, Category = Spawning)
		TSubclassOf<class AActor> WhatToSpawn[SPAWNER_ARRAY_SIZE];
	//the maximum amount of time untill a new spawn happens
	UPROPERTY(EditAnywhere)
		float RespawnMaxTime;
	//The minimum amount of time untill a new spawn happens
	UPROPERTY(EditAnywhere)
		float RespawnMinTime;
	//finds a random point within the BoxComponent
	UFUNCTION(BlueprintPure, Category = Spawning)
		FVector GetRandomPointInVolume();

	void EnableSpawning();

	void DisableSpawning();

	/** Handles the spawning of a new pickup */
	UFUNCTION(/*BlueprintCallable,*/ Category = Spawning)
		void SpawnPickup();
protected:
	UPROPERTY(EditAnywhere)
	float TimeTillStarted;
private:

	/** Whether or not spawning is enabled */
	bool bSpawningEnabled;
	//used for spawning
	AActor* SpawnedPickup;
	//used to keep track of the amount of objects in our array
	int8 ArraySize;
	//used for the respawn timer
	float TimeSpent;
	//The time till respawn
	float TimeTillRespawn;
	
	

	void GetNewRespawnTime();
	
};
