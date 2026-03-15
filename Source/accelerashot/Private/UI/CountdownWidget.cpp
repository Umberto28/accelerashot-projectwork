// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CountdownWidget.h"

#include "Game/LevelGameMode.h"
#include "Kismet/GameplayStatics.h"

void UCountdownWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	PlayAnimationForward(CountdownAnimation);
}

void UCountdownWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UCountdownWidget::CountDownAnimationFinished()
{
	ALevelGameMode* CurrGameMode = Cast<ALevelGameMode>(UGameplayStatics::GetGameMode(this));
	CurrGameMode->OnCountdownCompleted();
}
