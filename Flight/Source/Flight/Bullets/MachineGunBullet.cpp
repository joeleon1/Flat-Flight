// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "MachineGunBullet.h"
#include "enemyController.h"
#include "RealBoss.h"

AMachineGunBullet::AMachineGunBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &AMachineGunBullet::OnBeginOverlap);
}

void AMachineGunBullet::OnBeginOverlap(AActor* OtherActor)
{
	AenemyController* Enemy = Cast<AenemyController>(OtherActor);

	if (Enemy)
	{
		//Enemy->TakeDamge(Damage);
		UGameplayStatics::ApplyDamage(Enemy, Damage * DamageScale,
			NULL, GetOwner(), UDamageType::StaticClass());
		Destroy();
		return;
	}
	ARealBoss* Boss = Cast<ARealBoss>(OtherActor);
	if (Boss)
	{
		UGameplayStatics::ApplyDamage(Boss, Damage * DamageScale, NULL, GetOwner(), UDamageType::StaticClass());
		Destroy();
		return;
	}
}

