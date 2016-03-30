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
	//Sets the Player pawn to what ever is selected by the PlayerClass static variable
	void SetPlayerPawn();
	enum PLAYER_CLASS
	{
		BASIC, ATTACK, SPEED, DEFENCE,
	};



	virtual void BeginPlay() override;
	
	static PLAYER_CLASS PlayerClass;
private:
	TSubclassOf<APawn> BasicPlayerClass;
	TSubclassOf<APawn> AttackPlayerClass;
	TSubclassOf<APawn> DefencePlayerClass;
	TSubclassOf<APawn> SpeedPlayerClass;
};
