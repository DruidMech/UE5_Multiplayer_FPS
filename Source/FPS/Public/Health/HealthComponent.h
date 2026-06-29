// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FHealthChanged, UHealthComponent*, HealthComponent, float, OldValue, float, NewValue, AActor*, Instigator);

UENUM(BlueprintType)
enum class EDeathState : uint8
{
	NotDead,
	DeathStarted,
	DeathFinished
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION(BlueprintPure, Category = "FPS|Health")
	static UHealthComponent* FindHealthComponent(const AActor* Actor) { return IsValid(Actor) ? Actor->FindComponentByClass<UHealthComponent>() : nullptr; }
	
	UFUNCTION(BlueprintCallable)
	float GetHealthNormalized() const;
	
	// return true if lethal
	bool ChangeHealthByAmount(float Amount, AActor* Instigator);
	void ChangeMaxHealthByAmount(float Amount, AActor* Instigator);
	
	UPROPERTY(ReplicatedUsing = OnRep_DeathState)
	EDeathState DeathState;
	
	UPROPERTY(ReplicatedUsing = OnRep_Health)
	float Health;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth)
	float MaxHealth;
	
	UPROPERTY(BlueprintAssignable)
	FHealthChanged OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FHealthChanged OnMaxHealthChanged;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnRep_DeathState(EDeathState OldDeathState);
	
	UFUNCTION()
	void OnRep_Health(float OldValue);
	
	UFUNCTION()
	void OnRep_MaxHealth(float OldValue);
};
