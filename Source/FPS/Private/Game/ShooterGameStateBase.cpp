// Copyright Druid Mechanics


#include "Game/ShooterGameStateBase.h"

AShooterGameStateBase::AShooterGameStateBase()
{
	bHasFirstBloodBeenHad = false;
}

bool AShooterGameStateBase::HasFirstBloodBeenHad() const
{
	return bHasFirstBloodBeenHad;
}

void AShooterGameStateBase::UpdateLeader()
{
	bHasFirstBloodBeenHad = true;
}
