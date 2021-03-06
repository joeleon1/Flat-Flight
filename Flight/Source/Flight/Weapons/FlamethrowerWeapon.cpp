// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlamethrowerWeapon.h"



AFlamethrowerWeapon::AFlamethrowerWeapon()
{
	FireRate = 0.2f;
	SetMaxAmmo(200);
	static ConstructorHelpers::FObjectFinder<USoundBase>SoundOB(TEXT("SoundWave'/Game/Audio/Flamethrower.Flamethrower'"));
	FireSound = (USoundBase*)SoundOB.Object;

	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;

		FConstructorStatistics() :ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/FlamethrowerBullet_BP.FlamethrowerBullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;

	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}
}
