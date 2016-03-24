// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BasicWeapon.h"



ABasicWeapon::ABasicWeapon()
{
	FireRate = 1.0f;
	Ammo = -1;

	static ConstructorHelpers::FObjectFinder<USoundBase>SoundOB(TEXT("SoundWave'/Game/Audio/CannonFire.CannonFire'"));
	FireSound = (USoundBase*)SoundOB.Object;
	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;
		FConstructorStatistics():ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/CannonBullet_BP.CannonBullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;
	check(ConstructorStatistics.ProjectileClass.Object);
	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}

}


