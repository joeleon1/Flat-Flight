// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PaperPlayerShip.h"
#include "Engine.h"
#include "Weapons/BasicWeapon.h"
#include "FlightPlayerState.h"

APaperPlayerShip::APaperPlayerShip() :bIsFiring(false),bIsNuke(false)
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

	NukeWeapon = GetWorld()->SpawnActor<ANukeWeapon>();
	NukeWeapon->SetOwner(this);
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
	if (bIsNuke)
	{
		if(NukeWeapon->HasAmmo())
			NukeWeapon->Fire();
	}	

}

// Called to bind functionality to input
void APaperPlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APaperPlayerShip::StartFiring);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &APaperPlayerShip::EndFiring);
	InputComponent->BindAction(TEXT("Nuke"), EInputEvent::IE_Pressed, this, &APaperPlayerShip::StartNuke);
	InputComponent->BindAction(TEXT("Nuke"), EInputEvent::IE_Released, this, &APaperPlayerShip::EndNuke);

}

void APaperPlayerShip::SetWeapon(AFlightWeapon* Weapon)
{
	if(Weapon)
		CurrentWeapon = Weapon;
}
void APaperPlayerShip::AddShields(float Shields)
{
	AFlightPlayerState* playerState = Cast<AFlightPlayerState>(PlayerState);

	if (playerState)
	{
		playerState->Shields += Shields;
		if (playerState->Shields > playerState->MaxShields)
		{
			playerState->Shields = playerState->MaxShields;
		}
	}
}
void APaperPlayerShip::GetNuke()
{
	NukeWeapon->AddAmmo();
}