// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bullets/FlightBullet.h"
#include "NukeBullet.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ANukeBullet : public AFlightBullet
{
	GENERATED_BODY()
public:
		ANukeBullet();
	
	virtual void Tick(float DeltaTime)override;

protected:
	UPROPERTY(EditAnywhere)
		float ScaleOverTime;
};