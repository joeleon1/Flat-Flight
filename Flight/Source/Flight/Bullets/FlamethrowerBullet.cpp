// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlamethrowerBullet.h"
#include "enemyController.h"


AFlamethrowerBullet::AFlamethrowerBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &AFlamethrowerBullet::OnBeginOverlap);
}

void AFlamethrowerBullet::OnBeginOverlap(AActor* OtherActor)
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

