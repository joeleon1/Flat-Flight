// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BasicWeapon.h"



ABasicWeapon::ABasicWeapon()
{
	FireRate = 1.0f;
	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;

		FConstructorStatistics():ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/Bullet_BP.Bullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;

	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}
}
