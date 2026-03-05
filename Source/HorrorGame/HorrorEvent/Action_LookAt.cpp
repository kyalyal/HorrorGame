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

	//로직
	MyData = InPlayerData;

	GetWorld()->GetTimerManager().SetTimer(StartDelayTimerHandle, this, &UAction_LookAt::StartSequence, MyData.DelayBeforeLookingSequence, false);
}

void UAction_LookAt::StartSequence()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AActor* Target = MyData.LookAtActor.ActorToLook;

	if (PC && PC->GetPawn() && Target)
	{
		//입력 차단
		PC->SetIgnoreLookInput(true);
		PC->SetIgnoreMoveInput(true);

		// 회전 값 계산
		StartRotation = PC->GetControlRotation();

		FVector StartPos = PC->GetPawn()->GetPawnViewLocation(); //카메라 위치 기준
		FVector TargetPos = Target->GetActorLocation();

		TargetRotation = FRotationMatrix::MakeFromX(TargetPos - StartPos).Rotator();

		CurrentAlpha = 0.0f;

		GetWorld()->GetTimerManager().SetTimer(ActionTimerHandle, this, &UAction_LookAt::UpdateRotation, 0.01f, true);

	}
	else
	{
		Finish();
	}

}

void UAction_LookAt::UpdateRotation()
{
	//0~1
	CurrentAlpha = FMath::Clamp(CurrentAlpha + (0.01f * MyData.LookAtActor.TurnSpeed), 0.f, 1.f);

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FRotator NewRotation = FMath::Lerp(StartRotation, TargetRotation, CurrentAlpha);

		PC->SetControlRotation(NewRotation);
	}

	if (CurrentAlpha >= 1.f)
	{
		GetWorld()->GetTimerManager().ClearTimer(ActionTimerHandle);
		
		GetWorld()->GetTimerManager().SetTimer(ActionTimerHandle, this, &UAction_LookAt::Finish, MyData.LookAtActor.KeepLookingDuration, false);
	}

}
