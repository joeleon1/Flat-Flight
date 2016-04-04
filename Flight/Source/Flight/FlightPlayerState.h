// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "FlightGameMode.h"
#include "FlightPlayerState.generated.h"
/**
 * 
 */
#define SCREEN_WIDTH 2560
#define SCREEN_HEIGHT 1450
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
	int8 Lives = 3;
	UPROPERTY()
	int8 CurrentCombo = 1;
	UPROPERTY()
	float MaxHealth = 100;
	UPROPERTY()
	float MaxShields = 50;
	UPROPERTY()
	int16 ShotsFired = 0;
	UPROPERTY()
	int16 EnemiesKilled= 0;
	UPROPERTY()
	int32 ActualScore = 0;
};
