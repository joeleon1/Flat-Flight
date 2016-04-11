// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightWeapon.h"
#include "FlightPlayerState.h"
#include "FlightPlayer.h"
AFlightWeapon::AFlightWeapon():WeaponLevel(1)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFlightWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceShot+= DeltaTime;
}
void AFlightWeapon::MakeBullet(FVector Vector, FRotator Rotator,float DamageScale)
{
	AFlightBullet* Bullet;
	
	Bullet = GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, Vector, Rotator);
	Bullet->SetLevel(WeaponLevel);
	Bullet->SetOwner(GetOwner());

	Bullet->SetDamageScale(DamageScale);
}
void AFlightWeapon::Fire()
{
	if (TimeSinceShot > FireRate && HasAmmo())
	{
		AFlightPlayer* Player = Cast<AFlightPlayer>(GetOwner());
		if (Player)
		{
			AFlightPlayerState* State = Cast<AFlightPlayerState>(Player->PlayerState);
			if (State)
			{
				State->ShotsFired++;
			}
		}
		TimeSinceShot = 0;
		Ammo--;
		if(FireSound)
			UGameplayStatics::PlaySoundAtLocation(this,FireSound , GetOwner()->GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);

		check(GetOwner());
		FVector Location = GetOwner()->GetActorLocation();
		MakeBullet(Location, FRotator(0, 90, 0),Player->GetDamageMultiplier());
		MakeBullet(Location, FRotator(0, -90, 0), Player->GetDamageMultiplier());
		if (WeaponLevel >= 2)
		{
			MakeBullet(Location, FRotator(45, 90, 0), Player->GetDamageMultiplier());
			MakeBullet(Location, FRotator(45, -90, 0), Player->GetDamageMultiplier());
		}
		if (WeaponLevel == 3)
		{
			Location.Y += 50;
			MakeBullet(Location,FRotator(90,90,0), Player->GetDamageMultiplier());
			Location.Y -= 100;
			MakeBullet(Location,FRotator(90,90,0), Player->GetDamageMultiplier());
		}
	}
	
}

void AFlightWeapon::LevelUp()
{
	FString Message = "Weapon Level Is ";
	Message += FString::FromInt(WeaponLevel);
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, Message);
	if (WeaponLevel != MAX_WEAPON_LEVEL)
	{
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Leveled");
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