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
	// Properties
	
	// Functions	
	virtual void BeginPlay() override;
	
	void ShowHUD() const;
	
	void HideHUD() const;

public:
	// Properties
	UPROPERTY()
	UUserWidget* WidgetHUD;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetHUDClass;
	
	virtual void Tick(float DeltaTime) override;
};
