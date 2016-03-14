// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "MachineGunPowerUp.h"
#include "../Weapons/MachineGunWeapon.h"



void AMachineGunPowerUp::BeginPlay()
{
	Super::BeginPlay();

	Weapon = GetWorld()->SpawnActor<AMachineGunWeapon>();
}