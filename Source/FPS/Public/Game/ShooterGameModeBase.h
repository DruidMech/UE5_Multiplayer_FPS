// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameModeBase.generated.h"


UCLASS()
class FPS_API AShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	
	void RequestRespawn(ACharacter* Character, AController* Controller);
};
