// Copyright Druid Mechanics


#include "Elimination/EliminationComponent.h"

UEliminationComponent::UEliminationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UEliminationComponent::OnRoundReported(AActor* Attacker, AActor* Victim, bool bHit, bool bHeadShot, bool bLethal)
{
	
}


