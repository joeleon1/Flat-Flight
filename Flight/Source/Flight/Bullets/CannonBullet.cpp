// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "CannonBullet.h"




ACannonBullet::ACannonBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &ACannonBullet::OnBeginOverlap);
}

void ACannonBullet::OnBeginOverlap(AActor* OtherActor)
{
	//uncomment when we have an enemy class
	/*FlightEnemy* Enemy = Cast<FlightEnemy>(OtherActor);
	
	if(Enemy)
	{
	
		Enemy->TakeDamge(Damage);
		Destroy();
	}*/
}