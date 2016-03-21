// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "Weapons/FlightWeapon.h"
#include "Weapons/NukeWeapon.h"
#include "PaperPlayerShip.generated.h"
/**
 * 
 */

#define NUMBER_OF_POSSIBLE_WEAPONS 5
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

	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const & DamageEvent,AController * EventInstigator, AActor * DamageCauser)override;

	void AddWeapon(AFlightWeapon* NewWeapon);
	FORCEINLINE AFlightWeapon* GetWeapon() { return CurrentWeapon; }
	bool HasWeapon(UClass* WeaponClass);
	void LevelUpWeapon(UClass* WeaponToLevel);
	void AddShields(float Sheilds);
	void GetNuke();

	void CycleWeaponsUp();
	void CycleWeaponsDown();
	void EquipBasicWeapon();
	void EquipWeaponOne();
	void EquipWeaponTwo();
	void EquipWeaponThree();
	void EquipWeaponFour();
private:
	FORCEINLINE void StartFiring() { bIsFiring = true; }
	FORCEINLINE void EndFiring() { bIsFiring = false; }
	FORCEINLINE void StartNuke() { bIsNuke = true; }
	FORCEINLINE void EndNuke() { bIsNuke = false; }

	void EquipWeaponAtSlot(int8 Slot);
	void RemoveWeaponAtCurrentSlot();


	bool bIsFiring,bIsNuke;
	AFlightWeapon* CurrentWeapon;
	AFlightWeapon* StoredWeapons[NUMBER_OF_POSSIBLE_WEAPONS];
	int8 CurrentSlot;
	ANukeWeapon* NukeWeapon;

	
	
};
