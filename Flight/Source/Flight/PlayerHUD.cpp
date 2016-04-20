// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PlayerHUD.h"
#include "FlightPlayerState.h"
#include "FlightPlayer.h"
#include "Weapons/FlightWeapon.h"
#include "Weapons/BasicWeapon.h"

APlayerHUD::APlayerHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//use the RobotoDisanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOB(TEXT("/Game/Fonts/COPRGTB"));
	HUDFont = (UFont*)HUDFontOB.Object;

	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB(TEXT("/Game/Textures/Cannon"));
	CannonIMG = (UTexture*)HUDTextureOB.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB2(TEXT("/Game/Textures/Laser"));
	LaserIMG = (UTexture*)HUDTextureOB2.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB3(TEXT("/Game/Textures/MachineGun"));
	MachinegunIMG = (UTexture*)HUDTextureOB3.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB4(TEXT("/Game/Textures/Flamethrower"));
	FlamethrowerIMG = (UTexture*)HUDTextureOB4.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB5(TEXT("/Game/Textures/Heart"));
	HeartIMG = (UTexture*)HUDTextureOB5.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB6(TEXT("/Game/Textures/Shield"));
	ShieldIMG = (UTexture*)HUDTextureOB6.Object;
	static ConstructorHelpers::FObjectFinder<UTexture>HUDTextureOB7(TEXT("/Game/Textures/Nuke"));
	NukeIMG = (UTexture*)HUDTextureOB7.Object;
}

void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	//Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	//Get player info
	AFlightPlayer* Player1 = Cast<AFlightPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
	UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APlayerController* PlayerController1 = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FString currentWep;
	int16 ammoCount = 0;
	int health = 0;
	int maxHealth = 0;
	int shields = 0;
	int maxShields = 0;
	int combo = 0;
	int score = 0;
	int8 NukeAmmo = 0;
	int8 lives = 0;
	if (PlayerController1 && Player1) {
		//get playerstate
		AFlightPlayerState* PlayerState1 = Cast<AFlightPlayerState>(PlayerController1->PlayerState);
		currentWep = Player1->GetWeapon()->GetName();
		int32 underScore = currentWep.Find((FString)"_");
		currentWep.RemoveAt(underScore, currentWep.Len() - underScore);
		ammoCount = Player1->GetWeapon()->GetAmmo();
		health = PlayerState1->Health;
		shields = PlayerState1->Shields;
		maxHealth = PlayerState1->MaxHealth;
		maxShields = PlayerState1->MaxShields;
		combo = PlayerState1->CurrentCombo;
		score = PlayerState1->ActualScore;
		NukeAmmo = Player1->GetNukeAmmo();
		lives = PlayerState1->Lives;
		//get ammo
		//ammoCount = Player1->GetWeapon()->GetAmmo();
	}

	//draw equipped weapon
	int wepSizeX = 64;
	int wepSizeY = 64;
	int wepX = 64;
	int wepY = 64;
	if (currentWep == (FString)"BasicWeapon")
		DrawTexture(CannonIMG, wepX, wepY, wepSizeX, wepSizeY, 1, 1, 1, 1);
	if (currentWep == (FString)"LaserCannonWeapon")
		DrawTexture(LaserIMG, wepX, wepY, wepSizeX, wepSizeY, 1, 1, 1, 1);
	if (currentWep == (FString)"MachineGunWeapon")
		DrawTexture(MachinegunIMG, wepX, wepY, wepSizeX, wepSizeY, 1, 1, 1, 1);
	if (currentWep == (FString)"FlamethrowerWeapon")
		DrawTexture(FlamethrowerIMG, wepX, wepY, wepSizeX, wepSizeY, 1, 1, 1, 1);

	DrawTexture(NukeIMG, 0, ScreenDimensions.Y-wepSizeY, wepSizeX, wepSizeY, 1, 1, 1, 1);
	DrawText(FString().FromInt(NukeAmmo), FColor::Yellow, wepSizeX, ScreenDimensions.Y - wepSizeY, HUDFont);
	DrawText(FString().FromInt(lives), FColor::Yellow, 0, 0, HUDFont);
	AFlightGameMode* GameMode = Cast<AFlightGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		TArray<FScoreToDisplay> Scores = GameMode->GetScores();
		FScoreToDisplay Score;
		for (int32 i = 0;i != Scores.Num();++i)
		{
			Score = Scores[i];
			DrawText(FString().FromInt(Score.Score), FColor::Red, Score.XPos*ScreenDimensions.X, Score.YPos*ScreenDimensions.Y, HUDFont);
		}
	}

	//draw shields & health
	int barSizeX = 3;
	int hbarSizeY = 32;
	int sbarSizeY = 16;
	int xHP = 64;
	int yHP = 64 - (wepSizeY / 2);
	//bg
	DrawRect(FColor::Black, xHP-4, yHP-4, maxHealth * barSizeX + 8, hbarSizeY + 8);
	DrawRect(FColor::Black, xHP+6, yHP-26, maxShields * barSizeX + 8, sbarSizeY + 8);
	//bars
	DrawRect(FColor::Red, xHP, yHP, health*barSizeX, hbarSizeY);
	DrawRect(FColor::Blue, xHP+10, yHP-22, shields*barSizeX, sbarSizeY);
	//draw imgs
	DrawTexture(HeartIMG, xHP - 16, yHP, 32, 32, 1, 1, 1, 1);
	DrawTexture(ShieldIMG, xHP, yHP-22, 16, 16, 1, 1, 1, 1);
	
	//draw combo 
	if (combo > 0) {
		FVector comboSize;
		FString comboString = FString().FromInt(combo);
		comboString.InsertAt(0, (FString)"x");
		GetTextSize(comboString, comboSize.X, comboSize.Y, HUDFont);
		DrawText(comboString, FColor::Yellow, ScreenDimensions.X - comboSize.X - 64, 32, HUDFont);
	}

	//draw score
	FVector scoreSize;
	FString scoreString = FString().FromInt(score);
	GetTextSize(scoreString, scoreSize.X, scoreSize.Y, HUDFont);
	DrawText(scoreString, FColor::Yellow, ScreenDimensions.X - scoreSize.X - 64, scoreSize.Y - 32, HUDFont);


	//draw ammo
	if (currentWep != (FString)"BasicWeapon") {
		DrawText(FString().FromInt(ammoCount), FColor::Yellow, wepX + wepSizeX, wepY, HUDFont);
	}
}
