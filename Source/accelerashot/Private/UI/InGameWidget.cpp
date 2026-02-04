// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameWidget.h"

#include "Kismet/GameplayStatics.h"

void UInGameWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	RefToPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

void UInGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	
}
