// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UTextBlock* TimeText;
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UTextBlock* AmmoText;
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UProgressBar* SpeedBar;
	
	UPROPERTY(EditDefaultsOnly)
	ACharacter* RefToPlayer;
	
public:
	virtual void NativeConstruct() override;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
