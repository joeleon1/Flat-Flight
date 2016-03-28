// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "EnemyBullet.h"


// Sets default values
AEnemyBullet::AEnemyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this, &AEnemyBullet::onPlayerHit);
}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Handles collision with player
void AEnemyBullet::onPlayerHit(AActor* otherActor)
{
}



