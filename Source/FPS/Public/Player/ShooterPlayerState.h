// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ShooterPlayerState.generated.h"



UCLASS()
class FPS_API AShooterPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	AShooterPlayerState();
	
	void AddScoredElim();
	void AddDefeat();
	void AddHit();
	void AddMiss();
	void AddHeadShotElim();
	void AddSequentialElim(int32 SequenceCount);
	void UpdateHighestStreak(int32 StreakCount);
	void AddRevengeElim();
	void AddDethroneElim();
	void AddShowStopperElim();
	void GotFirstBlood();
	void IsNowWinner();
	void SetOnStreak(bool bIsOnStreak);
	void SetLastAttacker(APlayerState* Attacker);
	
	bool IsOnStreak() const;
	APlayerState* GetLastAttacker() const;
	int32 GetScoredElims() const;
	
private:
	int32 ScoredElims;
	int32 Defeats;
	int32 Hits;
	int32 Misses;
	bool bOnStreak; // How many elims do we have since we've spawned?
	int32 HeadShotElims;
	TMap<int32, int32> SequentialElims; // Sequential elims - multiple elims within a short period of time
	int32 HighestStreak;
	int32 RevengeElims;
	int32 DethroneElims;
	int32 ShowStopperElims;
	bool bFirstBlood;
	bool bWinner;
	
	TWeakObjectPtr<APlayerState> LastAttacker;
};
