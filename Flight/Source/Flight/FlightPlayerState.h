// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "FlightPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlightPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY()
	float Health = 100;
	UPROPERTY()
	float Shields = 0;

	UPROPERTY()
	float MaxShields = 50;

};
