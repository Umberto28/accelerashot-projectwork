// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/GoalZone.h"

#include "Components/BoxComponent.h"
#include "Game/LevelGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoalZone::AGoalZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	GoalBox = CreateDefaultSubobject<UBoxComponent>("DeathBox");
	GoalBox->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void AGoalZone::BeginPlay()
{
	Super::BeginPlay();
	
	GoalBox->OnComponentBeginOverlap.AddDynamic(this, &AGoalZone::OnGoalBoxOverlap);
}

void AGoalZone::OnGoalBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
	if (PlayerChar && OtherActor == PlayerChar)
	{
		ALevelGameMode* CurrGameMode = Cast<ALevelGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		
		if (CurrGameMode)
		{
			CurrGameMode->OnLevelCompleted();
		}
	}
}

// Called every frame
void AGoalZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

