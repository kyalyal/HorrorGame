// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorEvent/HorrorAction.h"

void UHorrorAction::Finish()
{
	OnActionFinished.Broadcast(this);
}