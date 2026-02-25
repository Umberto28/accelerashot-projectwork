// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Character/PlayerCharacter.h"
#include "Game/LevelGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetTextLibrary.h"

void UInGameWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	RefToPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if (RefToPlayer)
	{
		// AddDynamic OnAmmoChanged
	}

	if (ALevelGameState* GameState = Cast<ALevelGameState>(GetWorld()->GetGameState()))
	{
		GameState->OnTimeChanged.AddDynamic(this, &UInGameWidget::OnTimeStampChanged);
		OnTimeStampChanged(0.0f);
	}
	
	OnCountdownFinishedEvent.BindDynamic(this, &UInGameWidget::EnablePlayer);
	BindToAnimationFinished(CountdownAnim, OnCountdownFinishedEvent);
	PlayAnimationForward(CountdownAnim);
}

void UInGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UInGameWidget::OnAmmoChanged(int32 Current, int32 Max)
{
	AmmoText->SetText(FText::Format(
			FText::FromString("{0} / {1}"),
			FText::AsNumber(Current),
			FText::AsNumber(Max)
		));
}

void UInGameWidget::OnTimeStampChanged(float TimeStamp)
{
	FTimespan CurrTime = FTimespan::FromSeconds(TimeStamp);
	
	TimeText->SetText(FText::Format(
			FText::FromString("{0}:{1}:{2}:{3}"),
			UKismetTextLibrary::Conv_IntToText(CurrTime.GetHours(), false, true, 2, 2),
			UKismetTextLibrary::Conv_IntToText(CurrTime.GetMinutes(), false, true, 2, 2),
			UKismetTextLibrary::Conv_IntToText(CurrTime.GetSeconds(), false, true, 2, 2),
			UKismetTextLibrary::Conv_IntToText(CurrTime.GetFractionMilli(), false, true, 2, 2)
		));
}

void UInGameWidget::EnablePlayer()
{
	RefToPlayer->UpdateInput(true);
}
