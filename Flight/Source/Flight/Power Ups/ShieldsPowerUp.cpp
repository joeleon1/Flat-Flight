// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "../PaperPlayerShip.h"
#include "ShieldsPowerUp.h"



AShieldsPowerUp::AShieldsPowerUp() :Shields(50)
{
	OnActorBeginOverlap.AddDynamic(this, &AShieldsPowerUp::OnBeginOverlap);
}

void AShieldsPowerUp::OnBeginOverlap(AActor* OtherActor)
{
	APaperPlayerShip* Player = Cast<APaperPlayerShip>(OtherActor);

	if (Player)
	{
		Player->AddShields(Shields);
		Destroy();
	}
}


