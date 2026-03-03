// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorEvent/Action_LookAt.h"
#include "Kismet/GameplayStatics.h"
#include "HorrorCharacter.h"

bool UAction_LookAt::CheckHorrorAction()
{
	if (!Super::CheckHorrorAction()) return false;

	AHorrorCharacter* PlayerCharacter = Cast<AHorrorCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return !PlayerCharacter->IsDead();
}

void UAction_LookAt::LookAtActor(const FHE_Player& InPlayerData)
{
	if (!CheckHorrorAction())  return;

	//·ÎÁ÷


}
