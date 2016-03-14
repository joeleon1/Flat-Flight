// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightGameMode.h"
#include "FlightPlayerState.h"



AFlightGameMode::AFlightGameMode(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	//Used to pull blueprints from the content directory
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> CharacterClass;
		//This is where you the reference for the player blueprint
		FConstructorStatics() :CharacterClass(TEXT("Blueprint'/Game/MyPaperPlayerShip.MyPaperPlayerShip'"))
		{
		}
	};

	static FConstructorStatics ConstructorStatics;
	//If the player blueprint is found and available to be used
	if (ConstructorStatics.CharacterClass.Object)
	{
		//set it to be the default pawn for our players
		DefaultPawnClass = Cast<UClass>(ConstructorStatics.CharacterClass.Object->GeneratedClass);
		
	}
	PlayerStateClass = AFlightPlayerState::StaticClass();
	//Any other setting of game mode stuff goes here e.g. AI, HUD etc
}

void AFlightGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Anything that needs to be done after the world exists
}
