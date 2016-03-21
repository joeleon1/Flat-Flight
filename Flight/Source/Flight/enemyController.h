// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "enemyController.generated.h"

UCLASS()
class FLIGHT_API AenemyController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AenemyController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	// This will be used for calculating the strafing displacement.
	float strafingTime;

	// The enemy's downward speed.
	float downSpeed;

	// How far the enemy will strafe from side to side. Note that the enemy will go from one end to the other in the same amount of time. The wider it can weave, the faster it goes.
	float horBound;

	// How fast the enemy will fire.
	float fireRate;

	// Enemy's fire damage
	float fireDamage;

	// Enemy's health
	float health;

	
	// This function will cause the enemy ship to strafe. Pass to it deltaTime.
	void strafe(float timePassed)
	{
		FVector strafeLocation = GetActorLocation();
		float horDeviation = (FMath::Sin(strafingTime + timePassed) - FMath::Sin(strafingTime));
		strafeLocation.Y = horDeviation * horBound;
		strafingTime += timePassed;
		SetActorLocation(strafeLocation);
	}
};
