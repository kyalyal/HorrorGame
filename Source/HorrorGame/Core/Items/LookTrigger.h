// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Items/HorrorItemBase.h"
#include "LookTrigger.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API ALookTrigger : public AHorrorItemBase
{
	GENERATED_BODY()
	
public:

	ALookTrigger();

	void Looking();
	void ResetLooking();

	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE float GetMaxLookingDistance() { return MaxLookingDistance; }

protected:

	UPROPERTY()
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(EditAnywhere, Category = "LookingTrigger")
	TObjectPtr<class UBoxComponent> CollisionBox;

private:

	UPROPERTY(EditAnywhere, Meta = (AllowPrivateAccess = "true"), Category = "LookingTrigger")
	float LookingDuration = 3.f;

	float LookingCounter;

	UPROPERTY(EditAnywhere, Meta = (AllowPrivateAccess = "true"), Category = "LookingTrigger")
	float MaxLookingDistance = 500.f;

};
