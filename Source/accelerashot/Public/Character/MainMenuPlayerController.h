// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMainMenuPlayerController();
	
protected:
	/* ----- Properties ----- */	
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	UInputMappingContext* MainScreenIMC;
	
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	UInputMappingContext* MainMenuIMC;
	
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	UInputAction* AnyKeyAction;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;
	
	void OnGameStart();
};
