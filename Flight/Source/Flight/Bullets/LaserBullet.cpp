// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LaserBullet.h"
#include "enemyController.h"
#include "RealBoss.h"

ALaserBullet::ALaserBullet()
{
	OnActorEndOverlap.AddDynamic(this, &ALaserBullet::OnBeginOverlap);
}

void ALaserBullet::OnBeginOverlap(AActor* OtherActor)
{
	AenemyController* Enemy = Cast<AenemyController>(OtherActor);
	
	if (Enemy)
	{
		//Enemy->TakeDamge(Damage);
		UGameplayStatics::ApplyDamage(Enemy, Damage * DamageScale,
			NULL, GetOwner(), UDamageType::StaticClass());
		return;
	}
	ARealBoss* Boss = Cast<ARealBoss>(OtherActor);
	if (Boss)
	{
		UGameplayStatics::ApplyDamage(Boss, Damage * DamageScale, NULL, GetOwner(), UDamageType::StaticClass());
		return;
	}
}

