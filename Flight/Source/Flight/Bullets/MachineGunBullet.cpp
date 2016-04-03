// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "MachineGunBullet.h"
#include "enemyController.h"


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
		UGameplayStatics::ApplyDamage(Enemy, Damage,
			Instigator->GetController(), this, UDamageType::StaticClass());
		Destroy();
	}
}

