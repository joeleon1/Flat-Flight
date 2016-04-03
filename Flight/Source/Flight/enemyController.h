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

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)override;
	//used when the enemy collides with the player
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);



	// This will be used for calculating the strafing displacement.
	float strafingTime;

	// The enemy's downward speed.
	UPROPERTY(EditAnywhere)
	float downSpeed;

	// How far the enemy will strafe from side to side. Note that the enemy will go from one end to the other in the same amount of time. The wider it can weave, the faster it goes.
	UPROPERTY(EditAnywhere)
	float horBound;

	// How fast the enemy will fire.
	float fireRate;

	// Enemy's fire damage
	float fireDamage;

	// Enemy's health
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	float health;

	
	// This function will cause the enemy ship to strafe. Pass to it deltaTime.
	void move(float timePassed)
	{
		FVector strafeLocation = GetActorLocation();

		// This returns a number between -1 and 1, to be used as a scalar for where the enemy ship is.
		float horDeviation = (FMath::Sin(strafingTime + timePassed) - FMath::Sin(strafingTime));

		// Set the y location to be somewhere in the horizontal boundary, scaled by the horDeviation.
		strafeLocation.Y += horDeviation * horBound;
		strafeLocation.Z -= downSpeed;
		strafingTime += timePassed;
		SetActorLocation(strafeLocation);
	}

	// This function will cause the enemy ship to fire.
	void fire()
	{
		FVector playerLocation;
		FVector enemyLocation = GetActorLocation();
		FVector fireDirection = playerLocation - enemyLocation;
		fireDirection.Normalize();

	}

protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* Collider;

	//The score awarded to the player on death
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	int32 Score;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		USoundBase* EnemyDeathSound;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float CollisionDamage;
};
