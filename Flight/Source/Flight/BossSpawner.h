// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
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

	float timeToSpawnBoss = 60;

	float gameTime = 0;

	float minHeight = 0;
	float maxHeight = 1000;
	
	bool isBossSpawned = false;
	// ADD WHEN WE HAVE A BOSS CLASS
	/*UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<AbossController> BossClass;*/
};
