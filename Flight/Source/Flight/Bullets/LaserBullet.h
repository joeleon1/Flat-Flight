// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "LaserBullet.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ALaserBullet : public AFlightBullet
{
	GENERATED_BODY()
public:
	ALaserBullet();
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
};
