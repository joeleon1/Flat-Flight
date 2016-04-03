// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "enemyController.h"
#include "FlightPlayer.h"

// Sets default values
AenemyController::AenemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->AttachTo(RootComponent);
	Score = 1000;

	OnActorBeginOverlap.AddDynamic(this, &AenemyController::OnBeginOverlap);
}

// Called when the game starts or when spawned
void AenemyController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AenemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	move(DeltaTime);
}

float AenemyController::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		health -= ActualDamage;
		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (health <= 0.f)
		{
			AFlightPlayer* Player = Cast<AFlightPlayer>(DamageCauser);
			
			if (Player)
			{
				Player->AddScore(Score, this);
			}

			SetLifeSpan(0.001f);
		}
		if (EnemyDeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, EnemyDeathSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
		}
	}

	return ActualDamage;
}

void AenemyController::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);

	if (Player)
	{
		FDamageEvent Event;
		Player->TakeDamage(CollisionDamage, Event, NULL, this);
		Destroy();
	}
}
