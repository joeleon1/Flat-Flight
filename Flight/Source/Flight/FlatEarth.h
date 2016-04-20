// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FlatEarth.generated.h"

UCLASS()
class FLIGHT_API AFlatEarth : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlatEarth();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshOne;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshTwo;
	UPROPERTY(EditDefaultsOnly)
		float SwapPosition;
		float StartPosition;
};
