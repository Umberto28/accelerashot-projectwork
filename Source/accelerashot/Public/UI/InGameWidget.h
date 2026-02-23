// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Character/PlayerCharacter.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	/* ----- Properties ----- */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* TimeText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* AmmoText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UProgressBar* SpeedBar;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidgetAnim))
	UWidgetAnimation* CountdownAnim;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	APlayerCharacter* RefToPlayer;
	
	/* ----- Functions ----- */
	FWidgetAnimationDynamicEvent OnCountdownFinishedEvent;
	
public:
	/* ----- Functions ----- */	
	virtual void NativeConstruct() override;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION()
	void OnAmmoChanged(int32 Current, int32 Max);
	
	UFUNCTION()
	void OnTimeStampChanged(float ElapsedTime);
	
	UFUNCTION()
	void EnablePlayer();
};
