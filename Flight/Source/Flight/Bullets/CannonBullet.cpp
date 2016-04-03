// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "CannonBullet.h"
#include "enemyController.h"



ACannonBullet::ACannonBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &ACannonBullet::OnBeginOverlap);
}

void ACannonBullet::OnBeginOverlap(AActor* OtherActor)
{
	AenemyController* Enemy = Cast<AenemyController>(OtherActor);
	
	if(Enemy)
	{	
		//Enemy->TakeDamge(Damage);
		UGameplayStatics::ApplyDamage(Enemy, Damage, 
			Instigator->GetController(), this, UDamageType::StaticClass());
		Destroy();
	}
}