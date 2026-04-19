// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/CharacterInterface.h"
#include "Game/LevelGameMode.h"
#include "PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoNumberChanged, int32, CurrentAmmo, int32, MaxAmmo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpeedChanged, float, CurrentSpeed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTargetPoint);

UCLASS()
class ACCELERASHOT_API APlayerCharacter : public ACharacter, public ICharacterInterface
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

	UPROPERTY()
	ALevelGameMode* RefToGameMode;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CurrentTopSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxSpeed;
	
	/* ----- Functions ----- */	
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */

	UPROPERTY(BlueprintCallable, Category = "Player Events")
	FOnAmmoNumberChanged OnAmmoNumberChanged;
	
	UPROPERTY(BlueprintCallable, Category = "Player Events")
	FOnSpeedChanged OnSpeedChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanDash = false;
	
	/* ----- Functions ----- */	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void ResetPlayerState();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Player Events")
	void PlayerFailure();
};
