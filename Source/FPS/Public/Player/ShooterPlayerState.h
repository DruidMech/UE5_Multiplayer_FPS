// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ShooterPlayerState.generated.h"


class USpecialElim;
class USpecialElimData;
enum class ESpecialElimType : uint16;

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
	
	UFUNCTION(Client, Reliable)
	void Client_LostTheLead();
	
	UFUNCTION(Client, Reliable)
	void Client_ScoredElim(int32 ElimScore);
	
	UFUNCTION(Client, Reliable)
	void Client_SpecialElim(const ESpecialElimType& SpecialElim, int32 SequentialElimCount, int32 StreakCount, int32 ElimScore);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FPS|SpecialElims")
	TObjectPtr<USpecialElimData> SpecialElimData;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|SpecialElims")
	TSubclassOf<USpecialElim> SpecialElimWidgetClass;
	
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
	
	TArray<ESpecialElimType> DecodeElimBitmask(ESpecialElimType ElimTypeBitmask);
};
