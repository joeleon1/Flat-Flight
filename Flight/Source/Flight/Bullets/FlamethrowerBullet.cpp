// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlamethrowerBullet.h"

AFlamethrowerBullet::AFlamethrowerBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &AFlamethrowerBullet::OnBeginOverlap);
}

void AFlamethrowerBullet::OnBeginOverlap(AActor* OtherActor)
{
	//uncomment when we have an enemy class
	/*FlightEnemy* Enemy = Cast<FlightEnemy>(OtherActor);

	if(Enemy)
	{
	Enemy->TakeDamge(Damage);
	Destroy();
	}*/
}

