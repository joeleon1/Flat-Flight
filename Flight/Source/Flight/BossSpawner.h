// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RealBoss.h"
#include "BossSpawner.generated.h"

UCLASS()
class FLIGHT_API ABossSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABossSpawner();

	float timeToSpawnBoss = 45;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	
	float gameTime = 0;
	float speedToAssign = 3;

	bool isBossSpawned = false;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<ARealBoss> BossClass;

	void SpawnBoss();

};