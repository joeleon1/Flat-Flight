// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukePowerUp.h"
#include "../FlightPlayer.h"
ANukePowerUp::ANukePowerUp()
{
	OnActorBeginOverlap.AddDynamic(this, &ANukePowerUp::OnBeginOverlap);
}

void ANukePowerUp::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);

	if (Player)
	{
		Player->GetNuke();
	}
	Destroy();
}