// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "../Weapons/LaserCannonWeapon.h"
#include "LaserCannonPowerUp.h"

void ALaserCannonPowerUp::BeginPlay()
{
	Super::BeginPlay();

	Weapon = GetWorld()->SpawnActor<ALaserCannonWeapon>();
}