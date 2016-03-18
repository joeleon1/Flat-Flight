// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightWeapon.h"

AFlightWeapon::AFlightWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFlightWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceShot+= DeltaTime;
}

void AFlightWeapon::Fire()
{
	if (TimeSinceShot > FireRate && HasAmmo())
	{
		TimeSinceShot = 0;
	//	check(GetWorld());
		//check(ProjectileClass);
		Ammo--;
		check(GetOwner());
		GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, 90, 0));
		GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, -90, 0));

		FString AmmoCount(TEXT("Ammo : "));
		AmmoCount += FString::FromInt(Ammo);
		if(Ammo  >=0 )
			GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, AmmoCount);
	}
	
}

void AFlightWeapon::LevelUp()
{
	if (WeaponLevel != MAX_WEAPON_LEVEL)
	{
		WeaponLevel++;
		if (Ammo > 0)
		{
			MaxAmmo *= 2;
			Ammo = MaxAmmo;
		}
		
	}
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon Leveled Up");
}

#undef MAX_WEAPON_LEVEL