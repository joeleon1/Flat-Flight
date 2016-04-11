// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Weapons/FlightWeapon.h"
#include "Weapons/NukeWeapon.h"
#include "FlightPlayerMovementComponent.h"
#include "FlightPlayer.generated.h"
#define NUMBER_OF_POSSIBLE_WEAPONS 5

UCLASS()
class FLIGHT_API AFlightPlayer : public APawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AFlightPlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	void AddWeapon(AFlightWeapon* NewWeapon);
	FORCEINLINE AFlightWeapon* GetWeapon() { return CurrentWeapon; }
	bool HasWeapon(UClass* WeaponClass);
	void LevelUpWeapon(UClass* WeaponToLevel);
	void AddShields(float Sheilds);
	void GetNuke();

	void AddScore(int32 Score, AActor* CallingActor);

	void Reset();

	UFUNCTION(BlueprintCallable, Category = "Widget")
		void ShowDamageEffect();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isShowingDmgEffect = false;

	void CycleWeaponsUp();
	void CycleWeaponsDown();
	void EquipBasicWeapon();
	void EquipWeaponOne();
	void EquipWeaponTwo();
	void EquipWeaponThree();
	void EquipWeaponFour();

	void SetBasicPlayer();
	void SetAttackPlayer();
	void SetDefencePlayer();
	void SetSpeedPlayer();

	void MoveVertical(float Scale);
	void MoveHorizontal(float Scale);

	float GetDamageMultiplier() { return DamageMultiplier; }
protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* Collider;
	UPROPERTY(VisibleAnywhere)
		UFlightPlayerMovementComponent* MovementComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		USoundBase* SoundOnWeaponSwitch;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		USoundBase* ShieldsFadeSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		USoundBase* PlayerDeathSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float DamageMultiplier;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float DefenceMultiplier;


		APlayerStart* PlayerStart;
private:
	FORCEINLINE void StartFiring() { bIsFiring = true; }
	FORCEINLINE void EndFiring() { bIsFiring = false; }
	void StartNuke();
	void EndNuke();
	void Damage() { FDamageEvent Event;TakeDamage(10, Event, nullptr, nullptr); }

	void SetDefaults();
	void EquipWeaponAtSlot(int8 Slot);
	void RemoveWeaponAtCurrentSlot();

	bool bIsFiring, bIsNuke;
	AFlightWeapon* CurrentWeapon;
	AFlightWeapon* StoredWeapons[NUMBER_OF_POSSIBLE_WEAPONS];
	int8 CurrentSlot;
	float FlashTimer;
	ANukeWeapon* NukeWeapon;


	
};
