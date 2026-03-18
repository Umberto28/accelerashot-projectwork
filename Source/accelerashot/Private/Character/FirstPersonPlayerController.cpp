// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FirstPersonPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/InGameWidget.h"
#include "UI/PauseMenuWidget.h"

class FSlateApplication;

AFirstPersonPlayerController::AFirstPersonPlayerController()
{
	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

void AFirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetHUD) WidgetHUD->AddToViewport(0);
	
	if (WidgetPause)
	{
		WidgetPause->AddToViewport(1);
		WidgetPause->SetVisibility(ESlateVisibility::Hidden);
	}
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem && DefaultIMC)
	{
		Subsystem->AddMappingContext(DefaultIMC, 0);
	}
	
	DisableInput(this);
}

void AFirstPersonPlayerController::ShowHUD(bool Show) const
{
	if (WidgetHUD) WidgetHUD->SetVisibility(Show ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void AFirstPersonPlayerController::ShowPause(bool Show) const
{
	if (WidgetPause) WidgetPause->SetVisibility(Show ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
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
			ShowHUD(false);
			ShowPause(true);

			//GetPawn()->SetActorTickEnabled(false);
			bShowMouseCursor = true;
			bEnableClickEvents = true;
			bEnableMouseOverEvents = true;
		
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this, WidgetPause);
		
			break;
		
		case false:	
			ShowPause(false);
			ShowHUD(true);

			//GetPawn()->SetActorTickEnabled(true);
			bShowMouseCursor = false;
			bEnableClickEvents = false;
			bEnableMouseOverEvents = false;
		
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
			
			break;
	}
}
