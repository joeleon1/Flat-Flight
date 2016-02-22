// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightWeapon.h"

AFlightWeapon::AFlightWeapon() :TimeSinceShot(99)
{

}

void AFlightWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceShot += DeltaTime;
}

void AFlightWeapon::Fire()
{
	GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetActorLocation(), FRotator(0, 0, 0));
	GetWorld()->SpawnActor<AFlightBullet>(ProjectileClass, this->GetActorLocation(), FRotator(0, 0, 0));
}