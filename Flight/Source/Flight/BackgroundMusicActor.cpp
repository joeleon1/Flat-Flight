// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "BackgroundMusicActor.h"




// Called when the game starts or when spawned
void ABackgroundMusicActor::BeginPlay()
{
	Super::BeginPlay();
	if(BackgroundMusic)
		UGameplayStatics::PlaySoundAtLocation(this, BackgroundMusic, GetActorLocation(), FRotator(0, 0, 0), 0.09, 1.0, 65, nullptr);
	
}

