// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	/* ----- Properties ----- */
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Widgets")
	UUserWidget* WidgetMainScreen;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;
	
public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */	
	UFUNCTION(BlueprintImplementableEvent)
	void OnGameStart();
};
