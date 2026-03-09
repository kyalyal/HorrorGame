// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Items/LookTrigger.h"
#include "Components/BoxComponent.h"

ALookTrigger::ALookTrigger()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SCENECOMPONENT"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("COLLISIONBOX"));

	RootComponent = SceneComponent;
	CollisionBox->SetupAttachment(RootComponent);
}

void ALookTrigger::Looking()
{
	LookingCounter += GetWorld()->GetDeltaSeconds();

	if (LookingCounter >= LookingDuration)
	{
		LookingCounter = 0;
		HorrorEventCheck(EHorrorEventCheck::LookAtTrigger);
	}
}

void ALookTrigger::ResetLooking()
{
	LookingCounter = 0;
}

void ALookTrigger::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	GEngine->AddOnScreenDebugMessage(-1, DeltaSeconds, FColor::Green, FString::Printf(TEXT("Trigger Second %f"), LookingCounter));
}
