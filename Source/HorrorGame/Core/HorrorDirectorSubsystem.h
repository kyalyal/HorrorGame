// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Info/HorrorEventInfo.h"

#include "HorrorDirectorSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API UHorrorDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

	//이벤트를 실행시켜줄 매개체
	void HorrorEvent(const FHorrorEvent& HorrorEvent);
};
