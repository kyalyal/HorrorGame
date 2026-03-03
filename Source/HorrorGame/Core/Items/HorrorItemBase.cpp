// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Items/HorrorItemBase.h"
#include "Core/HorrorDirectorSubsystem.h"

// Sets default values
AHorrorItemBase::AHorrorItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHorrorItemBase::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AHorrorItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHorrorItemBase::HorrorEventCheck(EHorrorEventCheck Check)
{
	//얘 차례가 됐나?? 아니면 카운트를 올려줘..

	//이쪽에 들어가는 인덱스 이벤트는 실행될 차례가 됐다.
	TArray<int32> IndexCache;

	for (int32 i = 0; i < HorrorEvents.Num(); i++)
	{
		if (HorrorEvents[i].TriggerInteraction == Check)
		{
			//카운팅
			HorrorEvents[i].Counter += 1;

			if (HorrorEvents[i].AfterNTimes == HorrorEvents[i].Counter)
			{
				IndexCache.Add(i);

				if (HorrorEvents[i].DoOnce == false)
				{
					HorrorEvents[i].Counter = 0;
				}
			}
		}
	}

	if (IndexCache.Num())
	{
		//이벤트 실행..!!!

		//SubSystem.
		if (UHorrorDirectorSubsystem* EventDirector = GetWorld()->GetSubsystem<UHorrorDirectorSubsystem>())
		{
			for (const int32 Index : IndexCache)
			{
				GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Green, TEXT("Hello"));
				EventDirector->HorrorEvent(HorrorEvents[Index].HorrorEvent);
			}
		}
	}
}

