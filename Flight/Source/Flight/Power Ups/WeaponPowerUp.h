// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Power Ups/FlightPowerUp.h"
#include "../Weapons/FlightWeapon.h"
#include "WeaponPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AWeaponPowerUp : public AFlightPowerUp
{
	GENERATED_BODY()
public:
	AWeaponPowerUp();
	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);
protected:
	UPROPERTY(VisibleAnywhere)
	AFlightWeapon* Weapon;
	
	
};
