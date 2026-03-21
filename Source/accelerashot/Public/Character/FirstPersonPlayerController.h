// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonPlayerController.generated.h"

class UInputMappingContext;
class UInGameWidget;
class UPauseMenuWidget;

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API AFirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFirstPersonPlayerController();
	
protected:
	/* ----- Properties ----- */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WidgetUI")
	UInGameWidget* WidgetHUD;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WidgetUI")
	UPauseMenuWidget* WidgetPause;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	UInputMappingContext* DefaultIMC;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;
	
	void ShowHUD(bool Show) const;
	void ShowPause(bool Show) const;
	
	UFUNCTION(BlueprintCallable)
	void SetPauseGame();
	
	UFUNCTION(BlueprintCallable)
	void OnGamePaused(bool pause);
};
