// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/LevelGameMode.h"

#include "Character/FirstPersonPlayerController.h"
#include "Game/LevelGameState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/CountdownWidget.h"
#include "Character/CharacterInterface.h"

void ALevelGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// Initialize the level (Game state with stats, UI)
	CurrGameState = GetGameState<ALevelGameState>();
	CurrPlayerController = Cast<AFirstPersonPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	if (CurrGameState)
	{
		CurrGameState->InitLevel();
		//CurrGameState->StartTimer();
	}
	
	// Cutscene with level overview (?)
	
	// Countdown
	if (WidgetCountDown)
	{
		WidgetCountDown->AddToViewport(1);
		// WidgetCountDown->SetVisibility(ESlateVisibility::Hidden);
	}
}

void ALevelGameMode::OnLevelResumed()
{
	CurrPlayerController->OnGamePaused(false);
	WidgetCountDown->PlayAnimationForward(WidgetCountDown->GetCountdownAnimation());
}

void ALevelGameMode::OnLevelRestart()
{
	CurrGameState->ResetHitTargets();
	OnTargetsReset.Broadcast();

	WidgetCountDown->PlayAnimationForward(WidgetCountDown->GetCountdownAnimation());
}

void ALevelGameMode::OnLevelCompleted()
{
	float TimeStamp = CurrGameState->StopTimer();
	CurrPlayerController->DisableInput(CurrPlayerController);
	CurrPlayerController->GetPawn()->SetActorTickEnabled(false);

	// Score Calculation
	FinalScore = CurrGameState->CalculateScore(LevelTimeObjective, LevelTargetsObjective);
	
	// Camera change, UI, show mouse cursor
}

void ALevelGameMode::OnCountdownCompleted()
{
	if(CurrPlayerController->IsPaused())
	{
		// Is the resume countdown
		CurrPlayerController->SetPauseGame();
	}
	else
	{
		// Is the countdown at the beginning of the level
		CurrPlayerController->EnableInput(CurrPlayerController);
		CurrPlayerController->GetPawn()->SetActorTickEnabled(true);// Player must have tick enabled to change speed
		ICharacterInterface::Execute_DashWindow(CurrPlayerController->GetPawn(), 0.3f);
		CurrGameState->StartTimer();
	}
	
}
