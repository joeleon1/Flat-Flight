// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LaserDamage.generated.h"

UCLASS()
class FLIGHT_API ALaserDamage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserDamage();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
protected:
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* LaserParticleSystem;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float TimeTillDeath;
private:
	float TimeAlive;

};
