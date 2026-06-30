// Copyright Druid Mechanics


#include "Game/ShooterGameModeBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

void AShooterGameModeBase::RequestRespawn(ACharacter* Character, AController* Controller)
{
	if (!IsValid(Character) || !IsValid(Controller)) return;
	
	Character->Reset();
	Character->Destroy();
	
	TArray<AActor*> PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), PlayerStarts);
	ensure(PlayerStarts.Num() > 0);
	int32 Selection = FMath::RandRange(0, PlayerStarts.Num() - 1);
	
	RestartPlayerAtPlayerStart(Controller, PlayerStarts[Selection]);
}
