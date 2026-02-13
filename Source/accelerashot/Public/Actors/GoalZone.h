// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GoalZone.generated.h"

UCLASS()
class ACCELERASHOT_API AGoalZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalZone();

protected:
	/* ----- Properties ----- */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootScene;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBoxComponent* GoalBox;
	
	/* ----- Functions ----- */
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */
	UFUNCTION()
	void OnGoalBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void Tick(float DeltaTime) override;

};
