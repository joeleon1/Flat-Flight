// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FlightBullet.generated.h"

UCLASS()
class FLIGHT_API AFlightBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlightBullet();
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	float timeAlive;
protected:

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collider;

	UPROPERTY(VisibleAnywhere)
	float TimeTillDeath;
};
