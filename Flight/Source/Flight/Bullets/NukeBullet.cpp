// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukeBullet.h"

ANukeBullet::ANukeBullet()
{
	MovementComponent->InitialSpeed = 0;
	ScaleOverTime = 0;
}

void ANukeBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorRelativeScale3D(FVector(timeAlive * ScaleOverTime, timeAlive * ScaleOverTime, timeAlive * ScaleOverTime));

}
