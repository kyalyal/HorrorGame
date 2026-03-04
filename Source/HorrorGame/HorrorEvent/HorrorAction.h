// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HorrorAction.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_OneParam(FOnActionFinished, class UHorrorAction*)

UCLASS()
class HORRORGAME_API UHorrorAction : public UObject
{
	GENERATED_BODY()
	
public:
	virtual bool CheckHorrorAction() { return true; }

	//µ®∏Æ∞‘¿Ã∆Æ
	FOnActionFinished OnActionFinished;

	void Finish();
};
