// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "RealBoss.h"
#include "FlightPlayer.h"


// Sets default values
ARealBoss::ARealBoss()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	fired = false;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = Collider;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->AttachTo(RootComponent);
	Score = 10000;

	OnActorBeginOverlap.AddDynamic(this, &ARealBoss::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ARealBoss::BeginPlay()
{
	Super::BeginPlay();
	
}
void ARealBoss::AddLaserDamage()
{
	ALaserDamage* Damage = GetWorld()->SpawnActor<ALaserDamage>(LaserEmitter, GetActorLocation(), GetActorRotation());
	Damage->SetOwner(this);
}
// Called every frame
void ARealBoss::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	move(DeltaTime);


	// Checks if it's firing time. If it is, fire.
	if (FGenericPlatformMath::Frac(timePassed / fireRate) < 0.1 && !fired)
	{
		fire();

		// Set this so we're not constantly firing during this time.
		fired = true;
	}

	// If it's been a second since we fired, we set fired to false.
	if (FGenericPlatformMath::Frac(timePassed / fireRate) > 0.5 && fired)
	{
		// We are ready to fire again.
		fired = false;
	}

	if (GetActorLocation().Z < 0)
	{
		Destroy();
	}
	
	// If shipmesh is on screen and we 'just changed direction'
	if (GetActorLocation().Y >  2600) {
		isMovingLeft = true;
	}
	// If the shipmesh is offscreen and we DIDNT recently change direction
	else if (GetActorLocation().Y < -200) 
	{
		isMovingLeft = false;
	}
}

void ARealBoss::move(float deltaTime)
{
	int dir = 0;
	if (isMovingLeft)
	{
		dir = 1;
	}
	else {
		dir = -1;
	}
	FVector strafeLocation = GetActorLocation();

	// This returns a number between -1 and 1, to be used as a scalar for where the boss ship is.
	float vertDeviation = (FMath::Sin(deltaTime + timePassed) - FMath::Sin(timePassed));

	// Set the z location to be somewhere in the vertical boundary, scaled by the horDeviation.
	strafeLocation.Z += vertDeviation * vertBound;
	strafeLocation.Y -= horizontalSpeed * dir;
	timePassed += deltaTime;
	SetActorLocation(strafeLocation);
}

float ARealBoss::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
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
			GetWorld()->SpawnActor<AEnemyDeath>(SmokeEmitter, GetActorLocation(), GetActorRotation());
			Destroy();
			if (BossDeathSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, BossDeathSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
			}
		}
	}

	return ActualDamage;
}

void ARealBoss::OnBeginOverlap(AActor* OtherActor)
{
	AFlightPlayer* Player = Cast<AFlightPlayer>(OtherActor);

	if (Player)
	{
		FDamageEvent Event;
		Player->TakeDamage(CollisionDamage, Event, NULL, this);
		TakeDamage(1, Event, NULL, this);
	}
}

void ARealBoss::fire()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Trying to shoot.");
	//ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APawn* player = Controller->GetPawn();
	if (player)
	{
		FVector playerLocation = player->GetActorLocation();
		FVector enemyLocation = GetActorLocation();
		FVector fireDirection = playerLocation - enemyLocation;
		fireDirection.Normalize();
		makeBullet(fireDirection, this->GetActorRotation(), fireDamage);
	}
}

void ARealBoss::makeBullet(FVector Vector, FRotator Rotator, float damage)
{
	AEnemyBullet* Bullet;
	if (ProjectileClass)
	{
		//Spawn the blueprint version linked through the enemy blueprint ( Otherwise nothing will really happen)
		Bullet = GetWorld()->SpawnActor<AEnemyBullet>(ProjectileClass, this->GetActorLocation(), Vector.Rotation());
		if (Bullet) {
			Bullet->SetDamage(damage);
		}
	}
}