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

	//used when the enemy collides with the player
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)override;
	
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);



	// This will be used for calculating effects over time.
	float timePassed;

	// The enemy's downward speed.
	UPROPERTY(EditAnywhere)
	float downSpeed;

	// How far the enemy will strafe from side to side. Note that the enemy will go from one end to the other in the same amount of time. The wider it can weave, the faster it goes.
	UPROPERTY(EditAnywhere)
	float horBound;

	// How fast the enemy will fire.
	UPROPERTY(EditAnywhere)
	float fireRate;

	// Enemy's fire damage
	UPROPERTY(EditAnywhere)
	float fireDamage;

	// Shows whether enemy has already fired.
	bool fired;

	// Enemy's health
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	float health;

	
	// This function will cause the enemy ship to strafe. Pass to it deltaTime.
	void move(float deltaTime);

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
<<<<<<< HEAD

	void makeBullet(FVector Vector, FRotator Rotator, float damage);
=======
>>>>>>> origin/master
};
