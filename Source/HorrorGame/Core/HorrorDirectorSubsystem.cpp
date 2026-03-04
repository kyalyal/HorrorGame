// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HorrorDirectorSubsystem.h"
#include "HorrorEvent/Action_LookAt.h"

void UHorrorDirectorSubsystem::HorrorEvent(const FHorrorEvent& HorrorEvent)
{
	if (HorrorEvent.Player.LookAtActor.ActorToLook)
	{
		UAction_LookAt* PlayerAction = NewObject<UAction_LookAt>(this);
		PlayerAction->OnActionFinished.AddUObject(this, &UHorrorDirectorSubsystem::OnActionFinished);
		PlayerAction->LookAtActor(HorrorEvent.Player);

		ActiveAction.Add(PlayerAction);
	}

}

void UHorrorDirectorSubsystem::OnActionFinished(UHorrorAction* FinishedAction)
{
	if (FinishedAction)
	{
		ActiveAction.Remove(FinishedAction);
	}
	
}
