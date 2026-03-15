// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LevelGameMode.generated.h"

class ALevelGameState;
class AFirstPersonPlayerController;
class UCountdownWidget;

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
	
	UPROPERTY()
	AFirstPersonPlayerController* CurrPlayerController;
	
	UPROPERTY(EditDefaultsOnly)
	UCountdownWidget* WidgetCountDown;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;
	
public:
	/* ----- Properties ----- */
	UPROPERTY(BlueprintAssignable, Category = "Level Events")
	FOnTargetsReset OnTargetsReset;
	
	/* ----- Functions ----- */	
	void OnLevelResumed();
	
	void OnLevelRestart();
	
	void OnLevelCompleted();
	
	void OnCountdownCompleted();
};
