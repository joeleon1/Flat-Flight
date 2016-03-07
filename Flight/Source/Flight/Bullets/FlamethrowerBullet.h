// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "FlamethrowerBullet.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlamethrowerBullet : public AFlightBullet
{
	GENERATED_BODY()
	
public:
	AFlamethrowerBullet();
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
	
};
