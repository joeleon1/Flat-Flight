// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Power Ups/WeaponPowerUp.h"
#include "BasicWeaponPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ABasicWeaponPowerUp : public AWeaponPowerUp
{
	GENERATED_BODY()
public:
	ABasicWeaponPowerUp();
	UFUNCTION()
		void OnBeginOverlap(AActor* OtherActor);
	
};
