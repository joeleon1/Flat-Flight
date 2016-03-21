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
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		StoredWeapons[i] = nullptr;
	}
	StoredWeapons[0] = GetWorld()->SpawnActor<ABasicWeapon>();
	CurrentWeapon = StoredWeapons[0];
	CurrentWeapon->SetOwner(this);
	CurrentSlot = 0;
	NukeWeapon = GetWorld()->SpawnActor<ANukeWeapon>();
	NukeWeapon->SetOwner(this);
}
void APaperPlayerShip::RemoveWeaponAtCurrentSlot()
{	
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon Destroyed");
	CurrentWeapon->Destroy();
	for (int i = CurrentSlot;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		if (i + 1 == NUMBER_OF_POSSIBLE_WEAPONS)
		{
			StoredWeapons[i] = nullptr;
		}
		else
		{
			StoredWeapons[i] = StoredWeapons[i + 1];
		}
		
	}
}
float APaperPlayerShip::TakeDamage(float Damage, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	AFlightPlayerState* playerState = Cast<AFlightPlayerState>(PlayerState);

	if (playerState)
	{
		playerState->CurrentCombo = 0;
		if (playerState->Shields != 0)
		{
			float DamageLeft = Damage;
			if (playerState->Shields >= DamageLeft)
			{
				playerState->Shields -= DamageLeft;
			}
			else
			{
				DamageLeft -= playerState->Shields;
				playerState->Shields = 0;
				playerState->Health -= DamageLeft;
			}
		}
		else
		{
			playerState->Health -= Damage;
		}
	}
	return 0;
}
// Called every frame
void APaperPlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!CurrentWeapon->HasAmmo())
	{
		RemoveWeaponAtCurrentSlot();
		CurrentWeapon = StoredWeapons[0];
		CurrentSlot = 0;
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
	InputComponent->BindAction(TEXT("CycleDownWeapons"), EInputEvent::IE_Released, this, &APaperPlayerShip::CycleWeaponsDown);
	InputComponent->BindAction(TEXT("CycleUpWeapons"), EInputEvent::IE_Released, this, &APaperPlayerShip::CycleWeaponsUp);
	InputComponent->BindAction(TEXT("Basic"), EInputEvent::IE_Released, this, &APaperPlayerShip::EquipBasicWeapon);
	InputComponent->BindAction(TEXT("WeaponSlot1"), EInputEvent::IE_Released, this, &APaperPlayerShip::EquipWeaponOne);
	InputComponent->BindAction(TEXT("WeaponSlot2"), EInputEvent::IE_Released, this, &APaperPlayerShip::EquipWeaponTwo);
	InputComponent->BindAction(TEXT("WeaponSlot3"), EInputEvent::IE_Released, this, &APaperPlayerShip::EquipWeaponThree);
	InputComponent->BindAction(TEXT("WeaponSlot4"), EInputEvent::IE_Released, this, &APaperPlayerShip::EquipWeaponFour);
}
void APaperPlayerShip::EquipBasicWeapon()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon Set To Basic");
	CurrentSlot = 0;
	CurrentWeapon = StoredWeapons[0];
}
void APaperPlayerShip::EquipWeaponOne()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 1");
	EquipWeaponAtSlot(1);
}

void APaperPlayerShip::EquipWeaponTwo()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 2");
	EquipWeaponAtSlot(2);
}
void APaperPlayerShip::EquipWeaponThree()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 3");
	EquipWeaponAtSlot(3);
}
void APaperPlayerShip::EquipWeaponFour()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 4");
	EquipWeaponAtSlot(4);
}
void APaperPlayerShip::EquipWeaponAtSlot(int8 Slot)
{
	if (StoredWeapons[Slot] != nullptr)
	{
		CurrentSlot = Slot;
		CurrentWeapon = StoredWeapons[Slot];
	}
}
void APaperPlayerShip::CycleWeaponsDown()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried to cycle down");
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		CurrentSlot--;
		if (CurrentSlot == -1)
			CurrentSlot = 4;
		if (StoredWeapons[CurrentSlot] != nullptr)
		{
			FString message = "Found Weapon at Slot : ";
			message += FString::FromInt(CurrentSlot);
			GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, message);
			CurrentWeapon = StoredWeapons[CurrentSlot];
			return;
		}
	}
}
void APaperPlayerShip::CycleWeaponsUp()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried to cycle up");
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		CurrentSlot++;
		if (CurrentSlot == 5)
			CurrentSlot = 0;
		if (StoredWeapons[CurrentSlot] != nullptr)
		{
			FString message = "Found Weapon at Slot : ";
			message += FString::FromInt(CurrentSlot);
			GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, message);
			CurrentWeapon = StoredWeapons[CurrentSlot];
			return;
		}
	}
}
bool APaperPlayerShip::HasWeapon(UClass* WeaponClass)
{
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		if (StoredWeapons[i] != nullptr)
		{
			if (StoredWeapons[i]->GetClass() == WeaponClass)
			{
				return true;
			}
		}
	}
	return false;
}
void APaperPlayerShip::LevelUpWeapon(UClass* WeaponClass)
{
	//The only time it gets passed nullptr is if its the basic weapon
	if (WeaponClass == nullptr)
	{
		StoredWeapons[0]->LevelUp();
	}
	else
	{
		for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
		{
			if (StoredWeapons[i] != nullptr)
			{
				if (StoredWeapons[i]->GetClass() == WeaponClass)
				{
					StoredWeapons[i]->LevelUp();
				}
			}
		}

	}
}
void APaperPlayerShip::AddWeapon(AFlightWeapon* Weapon)
{
	if (Weapon)
	{
		for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
		{
			if (StoredWeapons[i] == nullptr)
			{
				StoredWeapons[i] = Weapon;
				CurrentWeapon = Weapon;
				CurrentSlot = i;
				return;
			}
		}
	}
}

#undef NUMBER_OF_POSSIBLE_WEAPONS
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