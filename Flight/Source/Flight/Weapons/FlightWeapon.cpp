// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightWeapon.h"

AFlightWeapon::AFlightWeapon() :TimeSinceShot(99)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFlightWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceShot += DeltaTime;
	if(GetOwner())
		TimeAlive += DeltaTime;
}

void AFlightWeapon::Fire()
{
	if (TimeSinceShot > FireRate)
	{
		TimeSinceShot = 0;
	//	check(GetWorld());
		//check(ProjectileClass);
		check(GetOwner());
		GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, 90, 0));
		GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, -90, 0));
	}
	
}