// Copyright Druid Mechanics


#include "Game/ShooterGameStateBase.h"

#include "Player/ShooterPlayerState.h"

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
	TArray<APlayerState*> LocalSortedPlayers = PlayerArray;
	LocalSortedPlayers.Sort([](const APlayerState& A, const APlayerState& B)
	{
		const AShooterPlayerState* PlayerA = Cast<AShooterPlayerState>(&A);
		const AShooterPlayerState* PlayerB = Cast<AShooterPlayerState>(&B);
		return PlayerA->GetScoredElims() > PlayerB->GetScoredElims();
	});
	
	Leaders.Empty();
	
	if (LocalSortedPlayers.Num() > 0)
	{
		int32 HighestScore = 0;
		for (APlayerState* Player : LocalSortedPlayers)
		{
			AShooterPlayerState* ShooterPS = Cast<AShooterPlayerState>(Player);
			if (IsValid(ShooterPS))
			{
				int32 PlayerScore = ShooterPS->GetScoredElims();
			
				// on the first iteration, set the highest score
				if (Leaders.Num() == 0)
				{
					HighestScore = PlayerScore;
					Leaders.Add(ShooterPS);
				}
				else if (PlayerScore == HighestScore)
				{
					Leaders.Add(ShooterPS); // Add to Leaders if scores are tied
				}
				else
				{
					break; // As it's sorted, no need to check further
				}
			}
		}
	}
	
	bHasFirstBloodBeenHad = true;
}

AShooterPlayerState* AShooterGameStateBase::GetSoleLeader() const
{
	if (Leaders.Num() == 1)
	{
		return Leaders[0];
	}
	return nullptr;
}

bool AShooterGameStateBase::IsTiedForTheLead(AShooterPlayerState* PlayerState)
{
	return Leaders.Contains(PlayerState);
}
