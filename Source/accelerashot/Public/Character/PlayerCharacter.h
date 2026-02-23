// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ACCELERASHOT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	/* ----- Properties ----- */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector StartingLocation;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRotator StartingRotation;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void ResetPlayerState();
	
	UFUNCTION(BlueprintCallable)
	void UpdateInput(bool Enable);
};
