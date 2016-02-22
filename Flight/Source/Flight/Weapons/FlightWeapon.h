// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Bullets/FlightBullet.h"
#include "GameFramework/Actor.h"
#include "FlightWeapon.generated.h"
/**
 * 
 */
UCLASS(abstract)
class FLIGHT_API AFlightWeapon: public AActor
{
public:
	GENERATED_BODY()
		/*This is a pure virtual class
		Inherit from this class for all guns in the game (This can be used with the AI if you see fit)
		*/

	//Set Deafults
	AFlightWeapon();

	//Update Timers
	virtual void Tick(float DeltaTime) override;

	//Called to have the gun fire its weapon
	virtual void Fire();
protected:

	//The type of bullet that will get spawned
	UPROPERTY()
	TSubclassOf<AFlightBullet> ProjectileClass;
	UPROPERTY(EditDefaultsOnly)
		float FireRate;
	float TimeSinceShot;
};
