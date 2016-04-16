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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	UPROPERTY(EditAnywhere)
		float spawnCheckRate = 2.5f;

	UPROPERTY(EditAnywhere)
		float spawnChance = 0.5f;

	float timeToNextCheck = 1;

	int numOfLoops = 0;
	int timesToIncreaseDifficulty = 10;

	float speedToAssign = 3;
	float speedIncrease = 0.5;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<ARealBoss> BossClass;

	void SpawnBoss();

};