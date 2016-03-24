// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "../Bullets/FlightBullet.h"
#include "GameFramework/Actor.h"
#include "FlightWeapon.generated.h"
/**
 * 
 */

#define MAX_WEAPON_LEVEL 3
UCLASS(abstract)
class FLIGHT_API AFlightWeapon: public AActor
{
public:
	GENERATED_BODY()
		/*This is a pure virtual class
		Inherit from this class for all guns in the game (This can be used with the AI if you see fit)
		*/

	//Set Deafults
	AFlightWeapon();
	virtual void Tick(float DeltaTime) override;
	//Called to have the gun fire its weapon
	virtual void Fire();

	FORCEINLINE bool HasAmmo() { return Ammo != 0; }
	FORCEINLINE int16 GetAmmo() { return Ammo; }
	void LevelUp();
protected:



	//used by classes inherited from this to set the ammo
	FORCEINLINE void SetMaxAmmo(const uint16 value) { MaxAmmo = value;Ammo = MaxAmmo; }
	
	//The type of bullet that will get spawned
	UPROPERTY()
	TSubclassOf<AFlightBullet> ProjectileClass;
	//Used for fire rates
	UPROPERTY(EditDefaultsOnly)
	float FireRate;
	float TimeSinceShot;
	//Used for weapons that can run out of ammo
	uint16 MaxAmmo;
	int16 Ammo;
	//Used to determine what level of bullets should fire
	int8 WeaponLevel = 0;

	//The sound that plays on fire and is pulled through the constructor of each weapon
	UPROPERTY()
	USoundBase* FireSound;

private:
	void MakeBullet(FVector Vector, FRotator Rotator = FRotator( 0,0,0 ));
};