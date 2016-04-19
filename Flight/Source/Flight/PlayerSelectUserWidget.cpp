// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PlayerSelectUserWidget.h"
#include "PlayerHUD.h"


void UPlayerSelectUserWidget::AttackPlayerSelected()
{
	SetPlayer(AFlightGameMode::ATTACK);
}
void UPlayerSelectUserWidget::DefencePlayerSelected()
{
	SetPlayer(AFlightGameMode::DEFENCE);
}

void UPlayerSelectUserWidget::SpeedPlayerSelected()
{
	SetPlayer(AFlightGameMode::SPEED);
}
void UPlayerSelectUserWidget::BalancedPlayerSelected()
{
	SetPlayer(AFlightGameMode::BASIC);
}

void UPlayerSelectUserWidget::SetPlayer(AFlightGameMode::PLAYER_CLASS PlayerClass)
{
	
	AFlightGameMode* GameMode = Cast<AFlightGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		GameMode->PlayerClass = PlayerClass;
		GameMode->HUDClass = APlayerHUD::StaticClass();
		SwitchMap();
	}
}
void UPlayerSelectUserWidget::SwitchMap()
{

	UGameplayStatics::OpenLevel((UObject*)GetWorld(), FName(TEXT("MapWithPowerUps")));
	
}