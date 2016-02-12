// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Bullets/FlightBullet.h"
/**
 * 
 */
class FLIGHT_API FlightGun
{
public:
	/*This is a pure virtual class (UE4 HATES c++ notation for pure virtual classes) 
	This class will not show up in the content manager in the engine since it is NOT a UObject.
	Inherit from this class for all guns in the game (This can be used with the AI if you see fit)
	*/
	FlightGun(TSubclassOf<AFlightBullet> ProjectileClass);
	~FlightGun();
private:
	//Gets set through the default constructor and is used for spawning their bullets
	UPROPERTY()
	TSubclassOf<AFlightBullet> ProjectileClass;
};
