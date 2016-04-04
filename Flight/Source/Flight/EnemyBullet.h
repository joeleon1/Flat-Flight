// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "EnemyBullet.generated.h"

/*This uses the flight bullet class that has all the functionality for bullets included and the specific bullet related properties 
are located in the blueprint implementation of this class under the projectile movement component*/

UCLASS()
class FLIGHT_API AEnemyBullet : public AFlightBullet
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
	void SetDamage(float value) { Damage = value; }
};
