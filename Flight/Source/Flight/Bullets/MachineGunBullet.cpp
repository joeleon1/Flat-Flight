// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "MachineGunBullet.h"


AMachineGunBullet::AMachineGunBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &AMachineGunBullet::OnBeginOverlap);
}

void AMachineGunBullet::OnBeginOverlap(AActor* OtherActor)
{
	/*FlightEnemy* Enemy = Cast<FlightEnemy>(OtherActor);

	if(Enemy)
	{
	Enemy->TakeDamge(Damage);
	Destroy();
	}*/
}

