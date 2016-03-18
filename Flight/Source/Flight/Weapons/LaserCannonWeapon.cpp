// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LaserCannonWeapon.h"




ALaserCannonWeapon::ALaserCannonWeapon()
{
	FireRate = 0.5f;
	SetMaxAmmo(100);
	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;

		FConstructorStatistics() :ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/LaserBullet_BP.LaserBullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;

	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}
}