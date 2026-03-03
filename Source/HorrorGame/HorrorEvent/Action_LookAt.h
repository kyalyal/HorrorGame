// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HorrorEvent/HorrorAction.h"
#include "Info/HorrorEventInfo.h"

#include "Action_LookAt.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API UAction_LookAt : public UHorrorAction
{
	GENERATED_BODY()
	

public:
	virtual bool CheckHorrorAction() override;

	UFUNCTION()
	void LookAtActor(const FHE_Player& InPlayerData);
};
