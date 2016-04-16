// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemyBullet.h"
#include "RealBoss.generated.h"

UCLASS()
class FLIGHT_API ARealBoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARealBoss();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Used when the Boss collides with the player
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)override;

	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor);

	// This will be used for calculating effects over time.
	float timePassed;

	// The Boss' downward speed.
	UPROPERTY(EditAnywhere)
		float horizontalSpeed;
	
	// How far the Boss will strafe from Top to Bot. Note that the enemy will go from one end to the other in the same amount of time. The wider it can weave, the faster it goes.
	UPROPERTY(EditAnywhere)
		float vertBound;

	// How fast the boss will fire.
	UPROPERTY(EditAnywhere)
		float fireRate;

	// Boss' fire damage
	UPROPERTY(EditAnywhere)
		float fireDamage;

	// Shows whether boss has already fired.
	bool fired;

	// Boss' health
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float health;

	// This function will cause the boss ship to strafe vertically. Pass to it deltaTime.
	void move(float deltaTime);

	// This function will cause the enemy ship to fire.
	void fire();


protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* Collider;

	// The score awarded to the player on death
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		int32 Score;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		USoundBase* BossDeathSound;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float CollisionDamage;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<AEnemyBullet> ProjectileClass;

	void makeBullet(FVector Vector, FRotator Rotator, float damage);
};
