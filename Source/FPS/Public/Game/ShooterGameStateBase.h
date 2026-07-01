// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ShooterGameStateBase.generated.h"


UCLASS()
class FPS_API AShooterGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	AShooterGameStateBase();
	
	bool HasFirstBloodBeenHad() const;
	void UpdateLeader();
private:
	
	bool bHasFirstBloodBeenHad;
};
