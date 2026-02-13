// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DeathZone.generated.h"

UCLASS()
class ACCELERASHOT_API ADeathZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathZone();

protected:
	/* ----- Properties ----- */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootScene;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBoxComponent* DeathBox;	
	
	/* ----- Functions ----- */
	virtual void BeginPlay() override;

public:
	/* ----- Properties ----- */
	
	/* ----- Functions ----- */
	UFUNCTION()
	void OnDeathBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void Tick(float DeltaTime) override;

};
