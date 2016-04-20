// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "enemyController.h"
#include "FlightPlayer.h"
#include "Bullets/LaserBullet.h"
// Sets default values
AenemyController::AenemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	fired = false;

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
}
void AenemyController::AddLaserDamage()
{
	ALaserDamage* Damage = GetWorld()->SpawnActor<ALaserDamage>(LaserEmitter, GetActorLocation(), GetActorRotation());
	Damage->SetOwner(this);
}
void AenemyController::move(float deltaTime)
{
	FVector strafeLocation = GetActorLocation();

	// This returns a number between -1 and 1, to be used as a scalar for where the enemy ship is.
	float horDeviation = (FMath::Sin(deltaTime + timePassed) - FMath::Sin(timePassed));

	// Set the y location to be somewhere in the horizontal boundary, scaled by the horDeviation.
	strafeLocation.Y += horDeviation * horBound;
	strafeLocation.Z -= downSpeed;
	timePassed += deltaTime;
	SetActorLocation(strafeLocation);
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
			
			Destroy();
			if (EnemyDeathSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, EnemyDeathSound, GetActorLocation(), FRotator(0, 0, 0), 0.1, 1.0, 0, nullptr);
			}
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
		TakeDamage(health, Event, NULL, this);
	}
}

void AenemyController::fire ()
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

void AenemyController::makeBullet(FVector Vector, FRotator Rotator, float damage)
{
	AEnemyBullet* Bullet;
	if (ProjectileClass)
	{
		//Spawn the blueprint version linked through the enemy blueprint ( Otherwise nothing will really happen)
		Bullet = GetWorld()->SpawnActor<AEnemyBullet>(ProjectileClass,this->GetActorLocation(), Vector.Rotation());
		Bullet->SetDamage(damage);
	}
	
	
}
