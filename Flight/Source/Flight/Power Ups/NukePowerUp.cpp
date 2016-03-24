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
		if(SoundOnPickUp)
			UGameplayStatics::PlaySoundAtLocation(this, SoundOnPickUp, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
		Player->GetNuke();
	}
	Destroy();
}