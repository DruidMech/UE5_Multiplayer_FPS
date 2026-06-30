// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EliminationComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UEliminationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEliminationComponent();
	
	UFUNCTION()
	void OnRoundReported(AActor* Attacker, AActor* Victim, bool bHit, bool bHeadShot, bool bLethal);
};
