// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukePowerUp.h"
#include "../PaperPlayerShip.h"
ANukePowerUp::ANukePowerUp()
{
	OnActorBeginOverlap.AddDynamic(this, &ANukePowerUp::OnBeginOverlap);
}

void ANukePowerUp::OnBeginOverlap(AActor* OtherActor)
{
	APaperPlayerShip* Player = Cast<APaperPlayerShip>(OtherActor);

	if (Player)
	{
		Player->GetNuke();
	}
	Destroy();
}