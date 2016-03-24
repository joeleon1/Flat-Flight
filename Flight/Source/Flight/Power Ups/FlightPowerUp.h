// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../Bullets/FlightBullet.h"
#include "../Weapons/FlightWeapon.h"
#include "FlightPowerUp.generated.h"

/*Pure Virtual class  for the power ups each will inherit from this class and override the OnBeginOverlap function for their functionality*/


UCLASS(abstract)
class FLIGHT_API AFlightPowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	
	AFlightPowerUp();
	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collider;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	USoundBase* SoundOnPickUp;
	UPROPERTY(EditDefaultsOnly)
	float TimeAlive;
	float TimeSinceSpawn;

	
};
