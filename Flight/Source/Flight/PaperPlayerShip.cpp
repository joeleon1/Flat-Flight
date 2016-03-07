// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PaperPlayerShip.h"
#include "Engine.h"
#include "Weapons/BasicWeapon.h"


APaperPlayerShip::APaperPlayerShip() :bIsFiring(false)
{
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void APaperPlayerShip::BeginPlay()
{
	Super::BeginPlay();
	BasicWeapon = GetWorld()->SpawnActor<ABasicWeapon>();
	BasicWeapon->SetOwner(this);
	CurrentWeapon = BasicWeapon;
}

// Called every frame
void APaperPlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!CurrentWeapon->IsAlive())
	{
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon power up over");
		CurrentWeapon->Destroy();
		CurrentWeapon = BasicWeapon;
	}
	if (bIsFiring)
	{
		if(CurrentWeapon)
			CurrentWeapon->Fire();
	}

}

// Called to bind functionality to input
void APaperPlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APaperPlayerShip::StartFiring);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &APaperPlayerShip::EndFiring);

}

void APaperPlayerShip::SetWeapon(AFlightWeapon* Weapon)
{
	if(Weapon)
		CurrentWeapon = Weapon;
}
void APaperPlayerShip::AddShields(float Sheilds)
{
	//Need to make a player state for out players for their health, score shields and other tracked information.
}
