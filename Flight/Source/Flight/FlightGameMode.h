// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FlightGameMode.generated.h"

/**
 * 
 */
USTRUCT()
struct FScoreToDisplay
{
	GENERATED_USTRUCT_BODY()

	FScoreToDisplay()
	{
		Score = 0;
		XPos = 0;
		YPos = 0;
		TimeOnScreen = 0;
	}
	UPROPERTY()
		int32 Score;
	UPROPERTY()
		float XPos;
	UPROPERTY()
		float YPos;
	UPROPERTY()
		float TimeOnScreen;
};

UCLASS()
class FLIGHT_API AFlightGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AFlightGameMode(const FObjectInitializer& ObjectInitializer);
	//Sets the Player pawn to what ever is selected by the PlayerClass static variable
	void SetPlayerPawn();
	void SetGameOver();

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	enum PLAYER_CLASS
	{
		BASIC, ATTACK, SPEED, DEFENCE,
	};
	//Add a score to be displayed
	void AddDisplayScore(int32 Score, FVector ActorLocation);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	TArray<FScoreToDisplay> GetScores() const { return ScoresAdded; }

	static PLAYER_CLASS PlayerClass;

	TSubclassOf<APawn> BasicPlayerClass;
	TSubclassOf<APawn> AttackPlayerClass;
	TSubclassOf<APawn> DefencePlayerClass;
	TSubclassOf<APawn> SpeedPlayerClass;
private:
	

	UPROPERTY()
		TArray<FScoreToDisplay> ScoresAdded;

	
};
