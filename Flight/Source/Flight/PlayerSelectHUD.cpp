// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "PlayerSelectHUD.h"

APlayerSelectHUD::APlayerSelectHUD()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UBlueprint> PlayerSelectWidget;
		FConstructorStatics(): PlayerSelectWidget(TEXT("WidgetBlueprint'/Game/Blueprints/PlayerSelectWidget.PlayerSelectWidget'"))
		{
		}
	};

	static FConstructorStatics ConstructorStatics;

	if (ConstructorStatics.PlayerSelectWidget.Object)
	{
		PlayerSelectWidgetClass = Cast<UClass>(ConstructorStatics.PlayerSelectWidget.Object->GeneratedClass);
	}
}

void APlayerSelectHUD::BeginPlay()
{
	Super::BeginPlay();

	PlayerSelectWidget = CreateWidget<UPlayerSelectUserWidget>(GetOwningPlayerController(), PlayerSelectWidgetClass);

	PlayerSelectWidget->AddToViewport(0);
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	
	if (Controller)
	{
		Controller->bShowMouseCursor = true;
		Controller->bEnableClickEvents = true;
	}
}


