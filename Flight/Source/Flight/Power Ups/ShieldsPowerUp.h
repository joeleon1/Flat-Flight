// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Power Ups/FlightPowerUp.h"
#include "ShieldsPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AShieldsPowerUp : public AFlightPowerUp
{
	GENERATED_BODY()
	
public:
	AShieldsPowerUp();
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
protected:
	UPROPERTY(EditDefaultsOnly)
	float Shields;
	
};
