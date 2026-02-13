// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonPlayerController.generated.h"

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
	UPROPERTY(EditDefaultsOnly, Category="WidgetUI")
	TSubclassOf<UUserWidget> WidgetHUDClass;
	
	UPROPERTY(EditDefaultsOnly, Category="WidgetUI")
	TSubclassOf<UUserWidget> WidgetPauseClass;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;
	
	void ShowHUD() const;
	void HideHUD() const;
	
	void ShowPause() const;
	void HidePause() const;

public:
	/* ----- Properties ----- */
	UPROPERTY(BlueprintReadOnly)
	UUserWidget* WidgetHUD;
	
	UPROPERTY(BlueprintReadOnly)
	UUserWidget* WidgetPause;
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void OnGamePaused();
};
