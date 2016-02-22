// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PlayerShip.h"


// Sets default values
APlayerShip::APlayerShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//lock camera position
	Camera->SetAbsolute(true, true);
	//Camera->AttachTo(root);


}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (bIsFiring)
	{
		//GetWorld()->SpawnActor()
	}

}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APlayerShip::StartFiring);
	InputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &APlayerShip::EndFiring);

}

void APlayerShip::SetWeapon(FlightGun* Weapon)
{
	CurrentWeapon = Weapon;
}

