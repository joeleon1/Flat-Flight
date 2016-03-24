// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "../FlightPlayer.h"
#include "ShieldsPowerUp.h"



AShieldsPowerUp::AShieldsPowerUp() :Shields(50)
{
	OnActorBeginOverlap.AddDynamic(this, &AShieldsPowerUp::OnBeginOverlap);
}

void AShieldsPowerUp::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);

	if (Player)
	{
		if(SoundOnPickUp)
			UGameplayStatics::PlaySoundAtLocation(this, SoundOnPickUp, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
		Player->AddShields(Shields);
		Destroy();
	}
}


