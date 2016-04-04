// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "LeaderboardHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API ALeaderboardHUD : public AHUD
{
	GENERATED_BODY()

		UPROPERTY()
		UFont* HUDFont;

	virtual void DrawHUD() override;
	
public:
	ALeaderboardHUD(const FObjectInitializer& ObjectInitializer);
};
