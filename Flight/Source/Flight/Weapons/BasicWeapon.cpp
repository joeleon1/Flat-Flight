// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BasicWeapon.h"



ABasicWeapon::ABasicWeapon()
{
	FireRate = 1.0f;
	TimeTillDeath = 9999.f;
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

void ABasicWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeAlive -= DeltaTime;
}


