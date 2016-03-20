// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "CameraFocusActor.h"


// Sets default values
ACameraFocusActor::ACameraFocusActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetAbsolute(true, true);

}

// Called when the game starts or when spawned
void ACameraFocusActor::BeginPlay()
{
	Super::BeginPlay();
	Camera->SetWorldLocation(FVector(0, 0, 0));
	Camera->SetWorldRotation(FRotator(0, 0, 0));


}

// Called every frame
void ACameraFocusActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

