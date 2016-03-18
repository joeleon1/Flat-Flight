// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Bullets/NukeBullet.h"
#include "NukeWeapon.generated.h"
#define MAX_AMMO 5
/**
 * 
 */
UCLASS()
class FLIGHT_API ANukeWeapon : public AActor
{
	GENERATED_BODY()
public:
	ANukeWeapon();

	void Fire();

	virtual void Tick(float DeltaTime) override;
	
	FORCEINLINE void AddAmmo() { if (Ammo != MAX_AMMO)Ammo++; }
	

	FORCEINLINE bool HasAmmo() { return Ammo != 0; }
	
private:
	TSubclassOf<ANukeBullet> ProjectileClass;
	int8 Ammo;
	float FireRate;
	float TimeSinceShot;
};