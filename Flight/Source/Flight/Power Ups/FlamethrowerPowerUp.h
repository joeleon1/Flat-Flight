// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Power Ups/WeaponPowerUp.h"
#include "FlamethrowerPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API AFlamethrowerPowerUp : public AWeaponPowerUp
{
	GENERATED_BODY()
public:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
