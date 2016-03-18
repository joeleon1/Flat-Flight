// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "../PaperPlayerShip.h"
#include "WeaponPowerUp.h"



AWeaponPowerUp::AWeaponPowerUp()
{
	OnActorBeginOverlap.AddDynamic(this, &AWeaponPowerUp::OnBeginOverlap);
	
}

void AWeaponPowerUp::OnBeginOverlap(AActor* OtherActor)
{
	APaperPlayerShip* Player = Cast<APaperPlayerShip>(OtherActor);

	if (Player)
	{
		if (Weapon != nullptr)
		{
			if (Player->HasWeapon(Weapon->GetClass()))
			{
				Player->LevelUpWeapon(Weapon->GetClass());
				Weapon->Destroy();
			}
			else
			{
				Weapon->SetOwner(Player);
				Player->AddWeapon(Weapon);
			}
			
			
		}
		Destroy();
	}
}
