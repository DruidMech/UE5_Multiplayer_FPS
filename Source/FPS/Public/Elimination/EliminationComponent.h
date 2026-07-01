// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EliminationComponent.generated.h"


class AShooterGameStateBase;
enum class ESpecialElimType : uint16;
class AShooterPlayerState;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UEliminationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEliminationComponent();
	
	UFUNCTION()
	void OnRoundReported(AActor* Attacker, AActor* Victim, bool bHit, bool bHeadShot, bool bLethal);

	UPROPERTY(EditDefaultsOnly, Category = "FPS|Elimination")
	float SequentialElimInterval;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Elimination")
	int32 ElimsNeededForStreak;
private:
	
	float LastElimTime;
	int32 SequentialElims;
	int32 Streak;
	
	AShooterPlayerState* GetPlayerStateFromActor(AActor* Actor);
	void ProcessHitOrMiss(bool bHit, AShooterPlayerState* AttackerPS);
	void ProcessElimination(bool bHeadShot, AShooterPlayerState* AttackerPS, AShooterPlayerState* VictimPS);
	void ProcessHeadshot(bool bHeadShot, ESpecialElimType& OutElimType, AShooterPlayerState* AttackerPS);
	void ProcessSequentialEliminations(ESpecialElimType& OutElimType, AShooterPlayerState* AttackerPS);
	void ProcessStreaks(ESpecialElimType& OutElimType, AShooterPlayerState* AttackerPS, AShooterPlayerState* VictimPS);
	void HandleFirstBlood(AShooterGameStateBase* GameState, ESpecialElimType& OutElimType, AShooterPlayerState* AttackerPS);
	void UpdateLeaderStatus(AShooterGameStateBase* GameState, ESpecialElimType& OutElimType, AShooterPlayerState* AttackerPS, AShooterPlayerState* VictimPS);
	bool HasSpecialElimTypes(const ESpecialElimType& SpecialElimType) const;
};
