// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemyBullet.generated.h"



UCLASS()
class FLIGHT_API AEnemyBullet : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorBeginOverlapSignature, class AActor*, otherActor);
public:	
	// Sets default values for this actor's properties
	AEnemyBullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere)
		USphereComponent* Collider;

	// This will determine how fast the bullet travels.
	UPROPERTY(EditAnywhere)
	float speed;

	// This will determine how long the bullet exists.
	UPROPERTY (EditAnywhere)
	float deathTimer;

	// This will record how much time has passed.
	float timePassed;

	// This will determine how much damage to do.
	float damage;

	// This will determine which direction the bullet travels.
	FVector direction;

	UFUNCTION()
	void onPlayerHit(AActor* otherActor);

	// This kills the bullet.
	void die();

	// This moves the bullet.
	void move();
};
