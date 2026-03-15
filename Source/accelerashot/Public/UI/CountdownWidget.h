// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CountdownWidget.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERASHOT_API UCountdownWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/* ----- Properties ----- */
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* CountdownAnimation;
		
	/* ----- Functions ----- */

public:
	/* ----- Functions ----- */	
	virtual void NativeConstruct() override;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void CountDownAnimationFinished();
	
	UWidgetAnimation* GetCountdownAnimation() const { return CountdownAnimation; };
};
