// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Weapons/FlightGun.h"
#include "PlayerShip.generated.h"

UCLASS()
class FLIGHT_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetWeapon(FlightGun* NewWeapon);

private:
	FORCEINLINE void StartFiring() { bIsFiring = true; }
	FORCEINLINE void EndFiring() { bIsFiring = false; }

	bool bIsFiring;
	FlightGun* CurrentWeapon;
	FlightGun* BasicWeapon;
	
};
