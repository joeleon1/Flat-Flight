// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "Weapons/FlightWeapon.h"
#include "Weapons/NukeWeapon.h"
#include "PaperPlayerShip.generated.h"
/**
 * 
 */
UCLASS()
class FLIGHT_API APaperPlayerShip : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	APaperPlayerShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetWeapon(AFlightWeapon* NewWeapon);
	void AddShields(float Sheilds);
	void GetNuke();
private:
	FORCEINLINE void StartFiring() { bIsFiring = true; }
	FORCEINLINE void EndFiring() { bIsFiring = false; }
	FORCEINLINE void StartNuke() { bIsNuke = true; }
	FORCEINLINE void EndNuke() { bIsNuke = false; }

	bool bIsFiring,bIsNuke;
	AFlightWeapon* CurrentWeapon;
	AFlightWeapon* BasicWeapon;
	ANukeWeapon* NukeWeapon;
	
	
};
