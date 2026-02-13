// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/LevelGameMode.h"

#include "Game/LevelGameState.h"
#include "Kismet/GameplayStatics.h"

void ALevelGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// Initialize the level (Game state with stats, UI)
	CurrGameState = Cast<ALevelGameState>(GetWorld()->GetGameState());
	if (CurrGameState) CurrGameState->InitLevel();
	
	// Cutscene with level overview (?)
	
	// Countdown
	
}

void ALevelGameMode::OnLevelCompleted()
{
	CurrGameState->StopTimer();
	
	// Camera change, Score calculation, UI, deactivate input, show mouse cursor
}
