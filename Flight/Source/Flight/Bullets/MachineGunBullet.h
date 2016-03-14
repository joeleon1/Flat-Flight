// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "MachineGunBullet.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AMachineGunBullet : public AFlightBullet
{
	GENERATED_BODY()

public:
	AMachineGunBullet();

	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
	
	
	
};
