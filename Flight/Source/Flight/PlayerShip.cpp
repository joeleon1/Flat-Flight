// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "Engine.h"
#include "PlayerShip.h"
#include "BasicWeapon.h"


// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	BasicWeapon = new ABasicWeapon();
	CurrentWeapon = BasicWeapon;
}

// Called every frame
void APlayerShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (bIsFiring)
	{
		
		CurrentWeapon->Fire();
	}

}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APlayerShip::StartFiring);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &APlayerShip::EndFiring);

}

void APlayerShip::SetWeapon(AFlightWeapon* Weapon)
{
	CurrentWeapon = Weapon;
}

