// Copyright Druid Mechanics


#include "Elimination/EliminationComponent.h"


UEliminationComponent::UEliminationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UEliminationComponent::OnRoundReported(AActor* Attacker, AActor* Victim, bool bHit, bool bHeadShot, bool bLethal)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit: %d, HeadShot: %d, Lethal: %d"), bHit, bHeadShot, bLethal);
}


