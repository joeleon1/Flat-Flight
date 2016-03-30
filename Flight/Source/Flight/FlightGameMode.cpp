// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlightGameMode.h"
#include "FlightPlayerState.h"
#include "PlayerHUD.h"

AFlightGameMode::PLAYER_CLASS AFlightGameMode::PlayerClass = BASIC;

AFlightGameMode::AFlightGameMode(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	//Used to pull blueprints from the content directory
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> BasicPlayerClass;
		ConstructorHelpers::FObjectFinder<UBlueprint> AttackPlayerClass;
		ConstructorHelpers::FObjectFinder<UBlueprint> DefencePlayerClass;
		ConstructorHelpers::FObjectFinder<UBlueprint> SpeedPlayerClass;
		//This is where you the reference for the player blueprint

		FConstructorStatics() :BasicPlayerClass(TEXT("Blueprint'/Game/Blueprints/Players/FlightPlayer_BP.FlightPlayer_BP'")),
			AttackPlayerClass(TEXT("Blueprint'/Game/Blueprints/Players/Player_Power_BP.Player_Power_BP'")),
			DefencePlayerClass(TEXT("Blueprint'/Game/Blueprints/Players/DefencePlayer_BP.DefencePlayer_BP'")),
			SpeedPlayerClass(TEXT("Blueprint'/Game/Blueprints/Players/SpeedPlayer_BP.SpeedPlayer_BP'"))
		{
		}
	};

	static FConstructorStatics ConstructorStatics;

	//If the player blueprint is found and available to be used

	if (ConstructorStatics.BasicPlayerClass.Object)
	{
		//set it to be the default pawn for our players
		BasicPlayerClass = Cast<UClass>(ConstructorStatics.BasicPlayerClass.Object->GeneratedClass);
	}
	if (ConstructorStatics.AttackPlayerClass.Object)
	{
		//set it to be the default pawn for our players
		AttackPlayerClass = Cast<UClass>(ConstructorStatics.AttackPlayerClass.Object->GeneratedClass);

	}
	
	if (ConstructorStatics.DefencePlayerClass.Object)
	{
		//set it to be the default pawn for our players
		DefencePlayerClass = Cast<UClass>(ConstructorStatics.DefencePlayerClass.Object->GeneratedClass);

	}
	
	if (ConstructorStatics.SpeedPlayerClass.Object)
	{
		//set it to be the default pawn for our players
		SpeedPlayerClass = Cast<UClass>(ConstructorStatics.SpeedPlayerClass.Object->GeneratedClass);

	}
	SetPlayerPawn();
	PlayerStateClass = AFlightPlayerState::StaticClass();
	//Any other setting of game mode stuff goes here e.g. AI, HUD etc
	HUDClass = APlayerHUD::StaticClass();
}

void AFlightGameMode::SetPlayerPawn()
{
	switch (AFlightGameMode::PlayerClass)
	{
	case BASIC:
		DefaultPawnClass = BasicPlayerClass;
		break;
	case ATTACK:
		DefaultPawnClass = AttackPlayerClass;
		break;
	case DEFENCE:
		DefaultPawnClass = DefencePlayerClass;
		break;
	case SPEED:
		DefaultPawnClass = SpeedPlayerClass;
		break;
	}
}


void AFlightGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Anything that needs to be done after the world exists
}
