// Copyright Druid Mechanics


#include "Elimination/EliminationComponent.h"

#include "GameFramework/Pawn.h"
#include "Player/ShooterPlayerState.h"
#include "ShooterTypes/ShooterTypes.h"


UEliminationComponent::UEliminationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UEliminationComponent::OnRoundReported(AActor* Attacker, AActor* Victim, bool bHit, bool bHeadShot, bool bLethal)
{
	AShooterPlayerState* AttackerPS = GetPlayerStateFromActor(Attacker);
	if (!IsValid(AttackerPS)) return;
	
	ProcessHitOrMiss(bHit, AttackerPS);
	
	if (!bHit) return; // Early return if it was a miss
	
	AShooterPlayerState* VictimPS = GetPlayerStateFromActor(Victim);
	if (!IsValid(VictimPS)) return;
	
	if (bLethal)
	{
		ProcessElimination(bHeadShot, AttackerPS, VictimPS);
	}
}

void UEliminationComponent::ProcessElimination(bool bHeadShot, AShooterPlayerState* AttackerPS, AShooterPlayerState* VictimPS)
{
	AttackerPS->AddScoredElim();
	VictimPS->AddDefeat();
	
	ESpecialElimType SpecialElimType{};
	
	// Process Head Shot
	// Process Sequential Eliminations
	// Process Streaks
	// Handle First Blood
	// Update Leader Status
	
	// if (Has Special Elim Types)
		// Tell the client which special elims we got
	// else (We just got a regular elim)
		// Just tell the client we got a regular elim
}

void UEliminationComponent::ProcessHitOrMiss(bool bHit, AShooterPlayerState* AttackerPS)
{
	if (bHit)
	{
		AttackerPS->AddHit();
	}
	else
	{
		AttackerPS->AddMiss();
	}
}

AShooterPlayerState* UEliminationComponent::GetPlayerStateFromActor(AActor* Actor)
{
	APawn* Pawn = Cast<APawn>(Actor);
	if (IsValid(Pawn))
	{
		return Pawn->GetPlayerState<AShooterPlayerState>();
	}
	return nullptr;
}



