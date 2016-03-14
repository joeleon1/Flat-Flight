// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Power Ups/FlightPowerUp.h"
#include "NukePowerUp.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ANukePowerUp : public AFlightPowerUp
{
	GENERATED_BODY()
public:
	ANukePowerUp();

	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
	
};
