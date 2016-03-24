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
	int ammoCount = 0;
	int health = 0;
	int maxHealth = 100;
	int shields = 0;
	int combo = 0;

	if (PlayerController1) {
		//get playerstate
		AFlightPlayerState* PlayerState1 = Cast<AFlightPlayerState>(PlayerController1->PlayerState);
		currentWep = Player1->GetWeapon()->GetName();
		int32 underScore = currentWep.Find((FString)"_");
		currentWep.RemoveAt(underScore, currentWep.Len() - underScore);
		health = PlayerState1->Health;
		shields = PlayerState1->Shields;
		combo = PlayerState1->CurrentCombo;
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
		
	//draw shields & health
	int barSizeX = 3;
	int barSizeY = 32;
	int xHP = 64;
	int yHP = 64 - (wepSizeY / 2);
	DrawRect(FColor::Red, xHP, yHP, health * barSizeX, barSizeY);
	DrawRect(FColor::Blue, xHP + 10, yHP - 10, shields * barSizeX, barSizeY);
	
	//draw combo
	if (combo > 0) {
		FVector comboSize;
		FString comboString = FString().FromInt(combo);
		comboString.InsertAt(0, (FString)"x");
		GetTextSize(comboString, comboSize.X, comboSize.Y, HUDFont);
		DrawText(comboString, FColor::Yellow, ScreenDimensions.X - comboSize.X - 64, 32, HUDFont);
	}

	//draw ammo
	if (currentWep != (FString)"BasicWeapon") {
		DrawText(FString().FromInt(ammoCount), FColor::Yellow, wepX + wepSizeX, wepY, HUDFont);
	}
}
