// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainMenuPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Game/MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"

AMainMenuPlayerController::AMainMenuPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem && MainScreenIMC)
	{
		Subsystem->AddMappingContext(MainScreenIMC, 0);
		
		if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			EnhancedInputComponent->BindAction(AnyKeyAction, ETriggerEvent::Started, this, &AMainMenuPlayerController::OnGameStart);
			//EnhancedInputComponent->BindAction(TurnLeftAction, ETriggerEvent::Started, this, &AMainMenuPlayerController::OnTurnLeft);
			//EnhancedInputComponent->BindAction(TurnRightAction, ETriggerEvent::Started, this, &AMainMenuPlayerController::OnTurnRight);
		}
	}
	
	SetInputMode(FInputModeGameOnly());
	ConsoleCommand("r.ScreenPercentage 200");
}

void AMainMenuPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainMenuPlayerController::OnGameStart()
{
	SetInputMode(FInputModeGameAndUI());
	
	if (AMainMenuGameMode* CurrGameMode = Cast<AMainMenuGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		CurrGameMode->OnGameStart();
	}
}
