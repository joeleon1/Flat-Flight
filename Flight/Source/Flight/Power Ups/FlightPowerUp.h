// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../Bullets/FlightBullet.h"
#include "FlightPowerUp.generated.h"

/*Pure Virtual class  for the power ups each will inherit from this class and override the OnBeginOverlap function for their functionality*/


UCLASS(abstract)
class FLIGHT_API AFlightPowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	
	AFlightPowerUp();
	
	//Each Power Up will override this function to give the appropriate effects to the player. It will ONLY fire when the power up overlaps with the player.
	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor) PURE_VIRTUAL(AFlightPowerUp::OnBeginOverlap,);

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collider;

	
};
