// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlamethrowerWeapon.h"



AFlamethrowerWeapon::AFlamethrowerWeapon()
{
	FireRate = 0.2f;
	TimeTillDeath = 10.0f;
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