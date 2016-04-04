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

	ULeaderboardSaveGame* SaveGameInstance = Cast<ULeaderboardSaveGame>(UGameplayStatics::CreateSaveGameObject(ULeaderboardSaveGame::StaticClass()));
	TArray<uint32> leaderboard = SaveGameInstance->ReadLeaderboard();

	for (int i = 0; i < 10; i++) {
		DrawText(FString().FromInt(leaderboard[i]), FColor::Yellow, ScreenDimensions.X / 2, ScreenDimensions.Y / i, HUDFont);
	}

}
