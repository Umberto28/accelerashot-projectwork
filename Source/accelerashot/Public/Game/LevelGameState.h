// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LevelGameState.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeChanged, float, ElapsedTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, float, NewScore);

UCLASS()
class ACCELERASHOT_API ALevelGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ALevelGameState();
	
protected:
	/* ----- Properties ----- */
	UPROPERTY()
	float TimeStamp;
	
	UPROPERTY()
	int32 TotalTarget;
	
	UPROPERTY()
	int32 HitTarget;
	
	UPROPERTY()
	float FinalScore;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> TargetClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<AActor*> Targets;
	
public:
	/* ----- Properties ----- */
	UPROPERTY(BlueprintAssignable, Category = "Level Events")
	FOnTimeChanged OnTimeChanged;

	UPROPERTY(BlueprintAssignable, Category = "Level Events")
	FOnScoreChanged OnScoreChanged;
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION(BlueprintCallable)
	void InitLevel();
		
	UFUNCTION()
	void StartTimer();

	void StopTimer();
	
	void ResetHitTargets();
};
