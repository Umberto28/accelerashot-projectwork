// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "Character/FirstPersonPlayerController.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	StartingLocation = GetActorLocation();
	StartingRotation = GetControlRotation();
	
	UpdateInput(false);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	
	// Speed
	
	// Bullets
}

void APlayerCharacter::UpdateInput(const bool Enable)
{	
	if (AFirstPersonPlayerController* PlayerCon = Cast<AFirstPersonPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
	{
		/*UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerCon->GetLocalPlayer());
		
		switch (Enable)
		{
			case true:
				Subsystem->AddMappingContext(DefaultIMC, 0);
				
			case false:
				Subsystem->RemoveMappingContext(DefaultIMC);
		}*/
	}
}

