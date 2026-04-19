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
	
	if (TargetClass)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetClass, Targets);
		TotalTarget = Targets.Num();
	}
}

void ALevelGameState::StartTimer()
{
	SetActorTickEnabled(true);
}

float ALevelGameState::StopTimer()
{
	SetActorTickEnabled(false);
	return TimeStamp;
}

void ALevelGameState::ResetTimer()
{
	TimeStamp = 0.0f;
	OnTimeChanged.Broadcast(TimeStamp);
}

void ALevelGameState::UpdateHitTargets()
{
	HitTarget += 1;
}

void ALevelGameState::ResetHitTargets()
{
	HitTarget = 0;
}

int32 ALevelGameState::CalculateScore(float TimeObjective, int32 TargetsObjective) const
{
	int32 FinalScore = 0;
	int32 TimeScore = (5000.f - FMath::Clamp((TimeStamp - TimeObjective) * 200, 0.f, 4500.f));
	int32 TargetScore = (50 * HitTarget);
	FinalScore += TimeScore + TargetScore;
	return FinalScore;
}
