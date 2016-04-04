// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LeaderboardSaveGame.h"

ULeaderboardSaveGame::ULeaderboardSaveGame()
{
	SaveSlotName = TEXT("TestSaveSlot");
	UserIndex = 0;
	Leaderboard.Add(0);
}
