// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukeWeapon.h"

ANukeWeapon::ANukeWeapon():Ammo(MAX_AMMO/2),FireRate(1),TimeSinceShot(0)
{
	PrimaryActorTick.bCanEverTick = true;
	struct FConstructorStatistics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> ProjectileClass;

		FConstructorStatistics() :ProjectileClass(TEXT("Blueprint'/Game/Blueprints/Bullets/NukeBullet_BP.NukeBullet_BP'"))
		{

		}
	};

	static FConstructorStatistics ConstructorStatistics;

	if (ConstructorStatistics.ProjectileClass.Object)
	{
		ProjectileClass = Cast<UClass>(ConstructorStatistics.ProjectileClass.Object->GeneratedClass);
	}
}

void ANukeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceShot+= DeltaTime;
}

void ANukeWeapon::Fire()
{
	if (HasAmmo() && TimeSinceShot > FireRate)
	{
		//iterate through all enemies and apply damage
		/*for (TActorIterator<AFlightEnemy> ActorItr(WorldRef); ActorItr; ++ActorItr)
		{
		}*/
		TimeSinceShot = 0;
		check(GetOwner());
		Ammo--;
		GetWorld()->SpawnActor<ANukeBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, 90, 0));
	}
}
