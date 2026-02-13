// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FirstPersonPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "UI/InGameWidget.h"

AFirstPersonPlayerController::AFirstPersonPlayerController()
{
	
}

void AFirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetHUDClass) WidgetHUD = CreateWidget(this, WidgetHUDClass);
	
	if (WidgetHUD) WidgetHUD->AddToViewport(0);
}

void AFirstPersonPlayerController::ShowHUD() const
{
	if (WidgetHUD)
	{
		WidgetHUD->SetVisibility(ESlateVisibility::Visible);
	}
}

void AFirstPersonPlayerController::HideHUD() const
{
	if (WidgetHUD)
	{
		WidgetHUD->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AFirstPersonPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
