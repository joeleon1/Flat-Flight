// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "CannonBullet.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ACannonBullet : public AFlightBullet
{
	GENERATED_BODY()
	
public:
	ACannonBullet();
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);

	
};
