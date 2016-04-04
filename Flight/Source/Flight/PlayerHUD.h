// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
		//Variable for storing the font
		UPROPERTY()
		UFont* HUDFont;
		
		UPROPERTY()
		UTexture* FlamethrowerIMG;
		UTexture* NukeIMG;
		UTexture* MachinegunIMG;
		UTexture* LaserIMG;
		UTexture* FlightIMG;
		UTexture* CannonIMG;
		UTexture* HeartIMG;
		UTexture* ShieldIMG;

	//Primary draw call for the HUD
	virtual void DrawHUD() override;

public:
	APlayerHUD(const FObjectInitializer& ObjectInitializer);
	
	
};
