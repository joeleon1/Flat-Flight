// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FlightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlightGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AFlightGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	
};
