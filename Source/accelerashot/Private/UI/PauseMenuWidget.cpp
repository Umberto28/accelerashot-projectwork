// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseMenuWidget.h"

#include "Game/LevelGameMode.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
		
	if (ResumeButton) ResumeButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnResumeClicked);
	if (RestartButton) RestartButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnRestartClicked);
	if (OptionsButton) OptionsButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnOptionsClicked);
	//if (QuitButton) QuitButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnQuitClicked);
}

void UPauseMenuWidget::OnResumeClicked()
{
	if (ALevelGameMode* GameMode = Cast<ALevelGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		SetVisibility(ESlateVisibility::Hidden);
		GameMode->OnLevelResumed();
	}
	// if (AFirstPersonPlayerController* PlayerController = Cast<AFirstPersonPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
	// {
	// 	PlayerController->OnGamePaused();
	// }
}

void UPauseMenuWidget::OnRestartClicked()
{
	// Add fade animation or similar
	
	const FName LevelName(UGameplayStatics::GetCurrentLevelName(GetWorld()));
	UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}

void UPauseMenuWidget::OnOptionsClicked()
{
	
}

/* Temporarily moved to Blueprint
void UPauseMenuWidget::OnQuitClicked()
{
	// Get ref to main menu level from the game instance
	// UGameplayStatics::GetGameInstance(GetWorld());
	
	// Go back to main menu
	//UGameplayStatics::OpenLevelBySoftObjectPtr();
	
	APlayerController* SpecificPlayer = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Quit,true);
}
*/