// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "LeaderboardSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ULeaderboardSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		uint32 UserIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		TArray<uint32> Leaderboard;

	ULeaderboardSaveGame();
	//void WriteToLeaderboard(uint32 newScore);
	//TArray<uint32> ReadLeaderboard();
};
