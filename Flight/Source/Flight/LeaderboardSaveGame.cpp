// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LeaderboardSaveGame.h"

ULeaderboardSaveGame::ULeaderboardSaveGame()
{
	SaveSlotName = TEXT("TestSaveSlot");
	UserIndex = 0;
}

/*void ULeaderboardSaveGame::WriteToLeaderboard(uint32 newScore)
{
	ULeaderboardSaveGame* LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
	LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	Leaderboard = LoadGameInstance->Leaderboard;
	Leaderboard.Add(newScore);
	Leaderboard.Sort();
	ULeaderboardSaveGame* SaveGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
	SaveGameInstance->Leaderboard = Leaderboard;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
}

TArray<uint32> ULeaderboardSaveGame::ReadLeaderboard()
{
	ULeaderboardSaveGame* LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
	LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	return LoadGameInstance->Leaderboard;
}*/
