// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LaserBullet.h"

ALaserBullet::ALaserBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &ALaserBullet::OnBeginOverlap);
}

void ALaserBullet::OnBeginOverlap(AActor* OtherActor)
{
	//uncomment when we have an enemy class
	/*FlightEnemy* Enemy = Cast<FlightEnemy>(OtherActor);

	if(Enemy)
	{
	Enemy->TakeDamge(Damage);
	}*/
}

