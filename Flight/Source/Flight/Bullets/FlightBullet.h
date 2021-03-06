// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FlightBullet.generated.h"
//I will be turning this into an Abstract class when types of bullets are decided.
UCLASS()
class FLIGHT_API AFlightBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlightBullet();
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE void SetLevel(uint8 value) { Damage *= value; }
	void SetDamageScale(float value)
	{
		DamageScale = value;
	}
protected:
	//When the bullet will kill its self
	UPROPERTY(EditAnywhere)
	float TimeTillDeath;
	float timeAlive;
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collider;
	//Damage the bullet does
	UPROPERTY(EditDefaultsOnly, Category = "Bullet Properties")
	float Damage;

	float DamageScale;
};
