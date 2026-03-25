// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoNumberChanged, int32, CurrentAmmo, int32, MaxAmmo);

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

	UPROPERTY(BlueprintCallable, Category = "Player Events")
	FOnAmmoNumberChanged OnAmmoNumberChanged;
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void ResetPlayerState();
};
