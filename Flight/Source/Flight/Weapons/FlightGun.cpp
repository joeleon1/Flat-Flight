// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightGun.h"

FlightGun::FlightGun(TSubclassOf<AFlightBullet> Projectiles) :ProjectileClass(Projectiles)
{
}

FlightGun::~FlightGun()
{
}
