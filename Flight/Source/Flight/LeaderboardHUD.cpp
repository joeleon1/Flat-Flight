// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "LeaderboardHUD.h"
#include "FlightPlayerState.h"
#include "FlightPlayer.h"

ALeaderboardHUD::ALeaderboardHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//use the RobotoDisanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOB(TEXT("/Game/Fonts/COPRGTB"));
	HUDFont = (UFont*)HUDFontOB.Object;
}

void ALeaderboardHUD::DrawHUD()
{
	//Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	//Call to the parent versions of DrawHUD
	Super::DrawHUD();

	//Get player info
	AFlightPlayer* Player1 = Cast<AFlightPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	int yrscore = 0;

	if (PlayerController1 && Player1) {
		//get playerstate
		AFlightPlayerState* PlayerState1 = Cast<AFlightPlayerState>(PlayerController1->PlayerState);
		yrscore = PlayerState1->Score;
	}

	//draw background
	DrawRect(FColor::Black, 0, 0, ScreenDimensions.X, ScreenDimensions.Y);

	//control to reset
	DrawText((FString)"r to reset.", FColor::Yellow, 0, 0, HUDFont);

	ULeaderboardSaveGame* LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
	LoadGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	TArray<uint32> leaderboard = LoadGameInstance->Leaderboard;

	bool doOnce = true;
	FVector numSize;
	for (int i = 0; i < leaderboard.Num(); i++) {
		FString num = FString().FromInt(i + 1);
		num.Append(".");
		GetTextSize(num, numSize.X, numSize.Y, HUDFont);
		DrawText(num, FColor::Yellow, ScreenDimensions.X / 2 - numSize.X, i * numSize.Y, HUDFont);
		DrawText(FString().FromInt(leaderboard[i]), FColor::Yellow, ScreenDimensions.X / 2, i * numSize.Y, HUDFont);
		if (doOnce && leaderboard[i] == yrscore) {
			FString scoreString = "Your Score ->";
			FVector scoreSize;
			GetTextSize(scoreString, scoreSize.X, scoreSize.Y, HUDFont);
			DrawText((FString)"Your Score ->", FColor::Yellow, ScreenDimensions.X / 2 - numSize.X - scoreSize.X, i * numSize.Y, HUDFont);
			doOnce = false;
		}
	}
}

