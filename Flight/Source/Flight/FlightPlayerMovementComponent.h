// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PawnMovementComponent.h"
#include "FlightPlayerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API UFlightPlayerMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere)
	float Speed;
};
