// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/LevelGameState.h"

#include "Kismet/GameplayStatics.h"

ALevelGameState::ALevelGameState()
{	
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.TickInterval = 0.01f;
}

void ALevelGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	TimeStamp += DeltaSeconds;

	OnTimeChanged.Broadcast(TimeStamp);
}

void ALevelGameState::InitLevel()
{
	TimeStamp = 0.0f;
	HitTarget = 0;
	FinalScore = 0.0f;
	
	if (TargetClass)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetClass, Targets);
		TotalTarget = Targets.Num();
	}
}

void ALevelGameState::StartTimer()
{
	TimeStamp = 0.0f;
	SetActorTickEnabled(true);
}

void ALevelGameState::StopTimer()
{
	SetActorTickEnabled(false);
}
