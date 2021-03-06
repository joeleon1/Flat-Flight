// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukeWeapon.h"
#include "../enemyController.h"

ANukeWeapon::ANukeWeapon():Ammo(MAX_AMMO/2),FireRate(1),TimeSinceShot(0)
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USoundBase>SoundOB(TEXT("SoundWave'/Game/Audio/Time_Bomb_Short-SoundBible_com-1562499525.Time_Bomb_Short-SoundBible_com-1562499525'"));
	FireSound = (USoundBase*)SoundOB.Object;

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
#undef MAX_AMMO
void ANukeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceShot+= DeltaTime;
}

void ANukeWeapon::Fire()
{
	if (HasAmmo() && TimeSinceShot > FireRate)
	{
		if(FireSound)
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 1, nullptr);
		//iterate through all enemies and apply damage
		/*for (TActorIterator<AenemyController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			UGameplayStatics::ApplyDamage(*ActorItr, 50,NULL, GetOwner(), UDamageType::StaticClass());
		}*/ 
		TimeSinceShot = 0;
		check(GetOwner());
		Ammo--;
		ANukeBullet* Bullet = GetWorld()->SpawnActor<ANukeBullet>(ProjectileClass, this->GetOwner()->GetActorLocation(), FRotator(0, 90, 0));
		Bullet->SetOwner(GetOwner());
	}
}
