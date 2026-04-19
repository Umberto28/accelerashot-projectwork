// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "Character/FirstPersonPlayerController.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	StartingLocation = GetActorLocation();
	StartingRotation = GetControlRotation();

	RefToGameMode = Cast<ALevelGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	SetActorTickEnabled(false);
	OnSpeedChanged.Broadcast(CurrentTopSpeed/MaxSpeed);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnSpeedChanged.Broadcast(CurrentTopSpeed/MaxSpeed);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::ResetPlayerState()
{
	// Transform
	SetActorLocation(StartingLocation);
	GetController()->SetControlRotation(StartingRotation);
	
	CurrentTopSpeed = 800.0f;
	OnSpeedChanged.Broadcast(CurrentTopSpeed/MaxSpeed);
	
	// Bullets
	
	RefToGameMode->OnLevelRestart();
}

