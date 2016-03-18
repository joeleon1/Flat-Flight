// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "MachineGunWeapon.h"

AMachineGunWeapon::AMachineGunWeapon()
{
	FireRate = 0.1f;
	SetMaxAmmo(500);
	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;

		FConstructorStatistics() :ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/MachineGunBullet_BP.MachineGunBullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;

	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}
}


