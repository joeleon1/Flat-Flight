// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightPlayer.h"
#include "EnemyBullet.h"


// Sets default values
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AEnemyBullet::OnBeginOverlap);
}
void AEnemyBullet::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);
	if (Player)
	{
		UGameplayStatics::ApplyDamage(Player, Damage, NULL, this, UDamageType::StaticClass());
		Destroy();
	}
}
