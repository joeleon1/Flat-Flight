// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "FlightGameMode.h"
#include "PlayerSelectUserWidget.generated.h"


/**
 * 
 */
UCLASS()
class FLIGHT_API UPlayerSelectUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "ButtonPress")
		void AttackPlayerSelected();
	UFUNCTION(BlueprintCallable, Category = "ButtonPress")
		void DefencePlayerSelected();
	UFUNCTION(BlueprintCallable, Category = "ButtonPress")
		void SpeedPlayerSelected();
	UFUNCTION(BlueprintCallable, Category = "ButtonPress")
		void BalancedPlayerSelected();
private:
	void SetPlayer(AFlightGameMode::PLAYER_CLASS PlayerClass);
	void SwitchMap();
	
	
};
