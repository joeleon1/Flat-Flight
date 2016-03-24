// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BasicWeaponPowerUp.h"
#include "../FlightPlayer.h"
#include "../Weapons/BasicWeapon.h"


ABasicWeaponPowerUp::ABasicWeaponPowerUp()
{
	OnActorBeginOverlap.RemoveDynamic(this, &AWeaponPowerUp::OnBeginOverlap);
	OnActorBeginOverlap.AddDynamic(this, &ABasicWeaponPowerUp::OnBeginOverlap);
	Weapon = nullptr;
}



void ABasicWeaponPowerUp::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);

	if (Player)
	{
		Player->LevelUpWeapon(nullptr);
	}
	Destroy();
}