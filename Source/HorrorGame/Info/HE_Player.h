// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HE_Player.generated.h"


USTRUCT(BlueprintType)
struct FHE_LookAtActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HorrorEvent")
	TObjectPtr<AActor> ActorToLook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HorrorEvent")
	float TurnSpeed = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HorrorEvent")
	float KeepLookingDuration = 2.f;
};


USTRUCT(BlueprintType)
struct FHE_Player
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HorrorEvent")
	FHE_LookAtActor LookAtActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HorrorEvent")
	float DelayBeforeLookingSequence = 0.01f;
};

