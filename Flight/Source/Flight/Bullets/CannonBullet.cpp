// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "CannonBullet.h"
#include "enemyController.h"
#include "RealBoss.h"


ACannonBullet::ACannonBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &ACannonBullet::OnBeginOverlap);
}

void ACannonBullet::OnBeginOverlap(AActor* OtherActor)
{
 	AenemyController* Enemy = Cast<AenemyController>(OtherActor);
	
	if(Enemy)
	{	
		UGameplayStatics::ApplyDamage(Enemy, Damage* DamageScale, 
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