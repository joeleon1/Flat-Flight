// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "PlayerSelectUserWidget.h"
#include "PlayerSelectHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHT_API APlayerSelectHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	APlayerSelectHUD();
	virtual void BeginPlay() override;

protected:
	TSubclassOf<UPlayerSelectUserWidget> PlayerSelectWidgetClass;

	UPROPERTY()
		UPlayerSelectUserWidget* PlayerSelectWidget;
	
	
};
