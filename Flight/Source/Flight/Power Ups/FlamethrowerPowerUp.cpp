// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "../Weapons/FlamethrowerWeapon.h"
#include "FlamethrowerPowerUp.h"


void AFlamethrowerPowerUp::BeginPlay()
{
	Super::BeginPlay();
	Weapon = GetWorld()->SpawnActor<AFlamethrowerWeapon>();
}