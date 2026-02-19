// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelGameState.h"
#include "GameFramework/GameModeBase.h"
#include "LevelGameMode.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTargetsReset);

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
	UPROPERTY(BlueprintAssignable, Category = "Level Events")
	static FOnTargetsReset OnTargetsReset;
	
	/* ----- Functions ----- */	
	void OnLevelRestart();
	
	void OnLevelCompleted();
};
