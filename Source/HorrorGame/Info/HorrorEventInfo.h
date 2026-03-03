// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Info/HE_Player.h"

#include "HorrorEventInfo.generated.h" //여기 뭐가 있구나...


UENUM(BlueprintType)
enum class EHorrorEventCheck : uint8
{
	Nothing UMETA(DisplayName = "Nothing"),
	LookAtTrigger UMETA(DisplayName = "LookAtTrigger")
};


USTRUCT(BlueprintType)
struct FHorrorEvent
{
	GENERATED_BODY()

public:

	//Player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Horror Event")
	FHE_Player Player;
	//Sound
	//...
};

USTRUCT(BlueprintType)
struct FHorrorEventsMaster
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Horror Event")
	EHorrorEventCheck TriggerInteraction; // 나 어떤 행동을 할거야!!

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Horror Event")
	int32 AfterNTimes = 1; //이 행동을 몇번해야 이벤트가 실행되게 만들거다.

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Horror Event")
	int32 Counter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Horror Event")
	bool DoOnce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Horror Event")
	FHorrorEvent HorrorEvent;
};