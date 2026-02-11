// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelGameState.h"
#include "GameFramework/GameModeBase.h"
#include "LevelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API ALevelGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	/* ----- Properties ----- */
	UPROPERTY()
	ALevelGameState* CurrGameState;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;
	
public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */	
	void OnLevelCompleted();
};
