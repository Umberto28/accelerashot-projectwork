// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FirstPersonPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

class FSlateApplication;

AFirstPersonPlayerController::AFirstPersonPlayerController()
{
	
}

void AFirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetHUDClass) WidgetHUD = CreateWidget(this, WidgetHUDClass);
	if (WidgetHUD) WidgetHUD->AddToViewport(0);
	
	if (WidgetPauseClass) WidgetPause = CreateWidget(this, WidgetPauseClass);
	if (WidgetPause)
	{
		WidgetPause->AddToViewport(1);
		WidgetPause->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AFirstPersonPlayerController::ShowHUD() const
{
	if (WidgetHUD) WidgetHUD->SetVisibility(ESlateVisibility::Visible);
}

void AFirstPersonPlayerController::HideHUD() const
{
	if (WidgetHUD) WidgetHUD->SetVisibility(ESlateVisibility::Hidden);
}

void AFirstPersonPlayerController::ShowPause() const
{
	if (WidgetPause) WidgetPause->SetVisibility(ESlateVisibility::Visible);
}

void AFirstPersonPlayerController::HidePause() const
{
	if (WidgetPause) WidgetPause->SetVisibility(ESlateVisibility::Hidden);
}

void AFirstPersonPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFirstPersonPlayerController::OnGamePaused()
{
	SetPause(!IsPaused());

	switch (IsPaused())
	{
		case true:
			HideHUD();
			ShowPause();
		
			bShowMouseCursor = true;
			bEnableClickEvents = true;
			bEnableMouseOverEvents = true;
			
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this, WidgetPause);
		
			break;
		
		case false:	
			HidePause();
			ShowHUD();
			
			bShowMouseCursor = false;
			bEnableClickEvents = false;
			bEnableMouseOverEvents = false;
		
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
			
			break;
	}
}
