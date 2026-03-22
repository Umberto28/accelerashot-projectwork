// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/MainMenuGameMode.h"

#include "Blueprint/UserWidget.h"

void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetMainScreen)
	{
		WidgetMainScreen->AddToViewport();
	}
}
