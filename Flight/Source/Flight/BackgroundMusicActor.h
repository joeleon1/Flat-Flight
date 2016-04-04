// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BackgroundMusicActor.generated.h"

UCLASS()
class FLIGHT_API ABackgroundMusicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		USoundBase* BackgroundMusic;

	
	
};
