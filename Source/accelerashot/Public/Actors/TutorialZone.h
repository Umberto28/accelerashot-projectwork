// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game/LevelGameState.h"
#include "Character/FirstPersonPlayerController.h"
#include "Components/BoxComponent.h"
#include "TutorialZone.generated.h"

UCLASS()
class ACCELERASHOT_API ATutorialZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATutorialZone();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootScene;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBoxComponent* TutorialBox;

	bool bIsTutorialActive = false;

	AFirstPersonPlayerController* RefToPlayerCtrl;

	ALevelGameState* CurrGameState;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnTutorialBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void CloseTutorial();

	virtual void Tick(float DeltaTime) override;

};
