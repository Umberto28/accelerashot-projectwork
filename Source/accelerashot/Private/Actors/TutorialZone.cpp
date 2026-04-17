// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TutorialZone.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATutorialZone::ATutorialZone()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);

	TutorialBox = CreateDefaultSubobject<UBoxComponent>("TutorialBox");
	TutorialBox->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void ATutorialZone::BeginPlay()
{
	Super::BeginPlay();
	CurrGameState = Cast<ALevelGameState>(UGameplayStatics::GetGameState(this));
	TutorialBox->OnComponentBeginOverlap.AddDynamic(this, &ATutorialZone::OnTutorialBoxOverlap);
}


// Called every frame
void ATutorialZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATutorialZone::OnTutorialBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AActor* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0); PlayerChar && OtherActor == PlayerChar)
	{
		RefToPlayerCtrl = Cast<AFirstPersonPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		RefToPlayerCtrl->SetPause(true);
		bIsTutorialActive = true;
	}
}

void ATutorialZone::CloseTutorial()
{
	RefToPlayerCtrl->SetPause(false);
}