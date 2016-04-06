// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "enemyController.h"
#include "EnemySpawner.generated.h"

UCLASS()
class FLIGHT_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<AenemyController> EnemyClass;

	void SpawnEnemy();

};
