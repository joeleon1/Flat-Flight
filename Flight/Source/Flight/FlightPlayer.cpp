// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightPlayer.h"
#include "Weapons/BasicWeapon.h"
#include "FlightPlayerState.h"
#include "FlightGameMode.h"
// Sets default values
AFlightPlayer::AFlightPlayer() :bIsFiring(false), bIsNuke(false),FlashTimer(99),DamageMultiplier(0),DefenceMultiplier(0)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	MovementComponent = CreateDefaultSubobject<UFlightPlayerMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AFlightPlayer::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PlayerStart = *ActorItr;
	}
	SetDefaults();
}
void AFlightPlayer::SetDefaults()
{
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		if (StoredWeapons[i])
		{
			StoredWeapons[i]->Destroy();
			StoredWeapons[i] = nullptr;
		}

	}
	StoredWeapons[0] = GetWorld()->SpawnActor<ABasicWeapon>();
	CurrentWeapon = StoredWeapons[0];
	CurrentWeapon->SetOwner(this);
	CurrentSlot = 0;
	if (NukeWeapon)
	{
		NukeWeapon->Destroy();
		NukeWeapon = nullptr;
	}

	NukeWeapon = GetWorld()->SpawnActor<ANukeWeapon>();
	NukeWeapon->SetOwner(this);
	if(PlayerStart)
		SetActorLocation(PlayerStart->GetActorLocation());


}

// Called every frame
void AFlightPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FlashTimer += DeltaTime;
	if (FlashTimer < 2)
	{
		if((int)(FlashTimer*10) % 2 == 0)
			ShipMesh->SetVisibility(!ShipMesh->bVisible);
	}
	if (FlashTimer > 2 && !ShipMesh->bVisible)
	{
		ShipMesh->SetVisibility(true);
	}

	if (!CurrentWeapon->HasAmmo())
	{
		RemoveWeaponAtCurrentSlot();
		CurrentWeapon = StoredWeapons[0];
		if (SoundOnWeaponSwitch)
			UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
		CurrentSlot = 0;
	}
	if (bIsFiring)
	{
		if (CurrentWeapon)
			CurrentWeapon->Fire();
	}
	if (bIsNuke)
	{
		if (NukeWeapon->HasAmmo())
			NukeWeapon->Fire();
	}
}

// Called to bind functionality to input
void AFlightPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AFlightPlayer::StartFiring);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &AFlightPlayer::EndFiring);
	InputComponent->BindAction(TEXT("Nuke"), EInputEvent::IE_Pressed, this, &AFlightPlayer::StartNuke);
	InputComponent->BindAction(TEXT("Nuke"), EInputEvent::IE_Released, this, &AFlightPlayer::EndNuke);
	InputComponent->BindAction(TEXT("CycleDownWeapons"), EInputEvent::IE_Released, this, &AFlightPlayer::CycleWeaponsDown);
	InputComponent->BindAction(TEXT("CycleUpWeapons"), EInputEvent::IE_Released, this, &AFlightPlayer::CycleWeaponsUp);
	InputComponent->BindAction(TEXT("Basic"), EInputEvent::IE_Released, this, &AFlightPlayer::EquipBasicWeapon);
	InputComponent->BindAction(TEXT("WeaponSlot1"), EInputEvent::IE_Released, this, &AFlightPlayer::EquipWeaponOne);
	InputComponent->BindAction(TEXT("WeaponSlot2"), EInputEvent::IE_Released, this, &AFlightPlayer::EquipWeaponTwo);
	InputComponent->BindAction(TEXT("WeaponSlot3"), EInputEvent::IE_Released, this, &AFlightPlayer::EquipWeaponThree);
	InputComponent->BindAction(TEXT("WeaponSlot4"), EInputEvent::IE_Released, this, &AFlightPlayer::EquipWeaponFour);
	InputComponent->BindAxis(TEXT("Vertical"), this, &AFlightPlayer::MoveVertical);
	InputComponent->BindAxis(TEXT("Horizontal"), this, &AFlightPlayer::MoveHorizontal);

	InputComponent->BindAction(TEXT("TakeDamage"), EInputEvent::IE_Released,this, &AFlightPlayer::Damage);
}

UPawnMovementComponent* AFlightPlayer::GetMovementComponent() const
{
	return MovementComponent;
}

void AFlightPlayer::MoveVertical(float Scale)
{
	GetMovementComponent()->AddInputVector(FVector(0, 0, Scale * 10));
}
void AFlightPlayer::MoveHorizontal(float Scale)
{
	GetMovementComponent()->AddInputVector(FVector(0, Scale* 10,0));
}

void AFlightPlayer::RemoveWeaponAtCurrentSlot()
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

void AFlightPlayer::AddScore(int32 Score, AActor* Actor)
{
	AFlightPlayerState* playerState = Cast<AFlightPlayerState>(PlayerState);

	if (playerState)
	{
		AFlightGameMode* GameMode = Cast<AFlightGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->AddDisplayScore(Score*playerState->CurrentCombo, Actor->GetActorLocation());
		}
		playerState->ActualScore += Score*playerState->CurrentCombo;
		playerState->CurrentCombo++;
		

		
	}
}

float AFlightPlayer::TakeDamage(float Damage, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	isShowingDmgEffect = true;

	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	AFlightPlayerState* playerState = Cast<AFlightPlayerState>(PlayerState);

	if (playerState)
	{
		playerState->CurrentCombo = 1;
		if (playerState->Shields != 0)
		{
			float DamageLeft = Damage*DamageMultiplier;
			if (playerState->Shields > DamageLeft)
			{
				playerState->Shields -= DamageLeft;
			}
			else
			{
				DamageLeft -= playerState->Shields;
				playerState->Shields = 0;
				if (ShieldsFadeSound)
				{
					UGameplayStatics::PlaySoundAtLocation(this, ShieldsFadeSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
				}
				playerState->Health -= DamageLeft;
			}
		}
		else
		{
			playerState->Health -= Damage;
		}

		if (playerState->Health <= 0)
		{
			playerState->Health = 100;
			playerState->Lives--;
			SetDefaults();
			FlashTimer = 0;
			//play death sound and make a timer to respawn.
			if (PlayerDeathSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, PlayerDeathSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
			}
			//write to leaderboard and change state
			AFlightPlayerState* playerState = Cast<AFlightPlayerState>(PlayerState);

			if (playerState)
			{
				ULeaderboardSaveGame* SaveGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
				SaveGameInstance->WriteToLeaderboard(playerState->ActualScore);
				AFlightGameMode* GameMode = Cast<AFlightGameMode>(GetWorld()->GetAuthGameMode());
				GameMode->SetGameOver();
			}
			GetWorld()->GetAuthGameMode()->RestartPlayer(GetWorld()->GetFirstPlayerController());
			
		}
	}

	
	return 0;
}

void AFlightPlayer::ShowDamageEffect() {

}

void AFlightPlayer::EquipBasicWeapon()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon Set To Basic");
	CurrentSlot = 0;
	CurrentWeapon = StoredWeapons[0];
	if (SoundOnWeaponSwitch)
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);

	
}
void AFlightPlayer::EquipWeaponOne()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 1");
	EquipWeaponAtSlot(1);
}

void AFlightPlayer::EquipWeaponTwo()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 2");
	EquipWeaponAtSlot(2);
}
void AFlightPlayer::EquipWeaponThree()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 3");
	EquipWeaponAtSlot(3);
}
void AFlightPlayer::EquipWeaponFour()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried Set To slot 4");
	EquipWeaponAtSlot(4);
}
void AFlightPlayer::EquipWeaponAtSlot(int8 Slot)
{
	if (StoredWeapons[Slot] != nullptr)
	{
		CurrentSlot = Slot;
		CurrentWeapon = StoredWeapons[Slot];
		if (SoundOnWeaponSwitch)
			UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
	}
}
void AFlightPlayer::CycleWeaponsDown()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried to cycle down");
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		CurrentSlot--;
		if (CurrentSlot == -1)
			CurrentSlot = 4;
		if (StoredWeapons[CurrentSlot] != nullptr && CurrentWeapon != StoredWeapons[CurrentSlot])
		{
			FString message = "Found Weapon at Slot : ";
			message += FString::FromInt(CurrentSlot);
			GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, message);
			CurrentWeapon = StoredWeapons[CurrentSlot];
			if (SoundOnWeaponSwitch)
				UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
			return;
		}
	}
}
void AFlightPlayer::CycleWeaponsUp()
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, "Weapon tried to cycle up");
	for (int i = 0;i < NUMBER_OF_POSSIBLE_WEAPONS;i++)
	{
		CurrentSlot++;
		if (CurrentSlot == 5)
			CurrentSlot = 0;
		if (StoredWeapons[CurrentSlot] != nullptr && CurrentWeapon != StoredWeapons[CurrentSlot])
		{
			FString message = "Found Weapon at Slot : ";
			message += FString::FromInt(CurrentSlot);
			GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, message);
			CurrentWeapon = StoredWeapons[CurrentSlot];
			if (SoundOnWeaponSwitch)
				UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
			return;
		}
	}
}
bool AFlightPlayer::HasWeapon(UClass* WeaponClass)
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
void AFlightPlayer::LevelUpWeapon(UClass* WeaponClass)
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
void AFlightPlayer::AddWeapon(AFlightWeapon* Weapon)
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
				if (SoundOnWeaponSwitch)
					UGameplayStatics::PlaySoundAtLocation(this, SoundOnWeaponSwitch, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
				return;
			}
		}
	}
}

#undef NUMBER_OF_POSSIBLE_WEAPONS
void AFlightPlayer::AddShields(float Shields)
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
void AFlightPlayer::GetNuke()
{
	NukeWeapon->AddAmmo();
}