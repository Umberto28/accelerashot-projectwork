// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/* ----- Properties ----- */
	// UI properties
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	UButton* ResumeButton;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	UButton* RestartButton;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	UButton* OptionsButton;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	UButton* QuitButton;
	
	// Class properties	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName MainMenuLevelName;
	
	/* ----- Functions ----- */
	virtual void NativeConstruct() override;
	
public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */
	UFUNCTION(BlueprintCallable)
	void OnResumeClicked();
	
	UFUNCTION(BlueprintCallable)
	void OnRestartClicked();
	
	UFUNCTION(BlueprintCallable)
	void OnOptionsClicked();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuitClicked();
};
