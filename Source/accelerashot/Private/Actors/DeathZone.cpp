// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DeathZone.h"

#include "Character/PlayerCharacter.h"
#include "Game/LevelGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADeathZone::ADeathZone()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	DeathBox = CreateDefaultSubobject<UBoxComponent>("DeathBox");
	DeathBox->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void ADeathZone::BeginPlay()
{
	Super::BeginPlay();
	
	DeathBox->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::OnDeathBoxOverlap);
}

void ADeathZone::OnDeathBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* PlayerChar = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if (PlayerChar && OtherActor == PlayerChar)
	{
		PlayerChar->ResetPlayerState();
		
		if (ALevelGameMode* CurrGameMode = Cast<ALevelGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			CurrGameMode->OnLevelRestart();
		}
	}
}

// Called every frame
void ADeathZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

