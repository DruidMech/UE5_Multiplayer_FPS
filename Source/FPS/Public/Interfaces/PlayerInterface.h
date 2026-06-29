// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerInterface.generated.h"

struct FGameplayTag;
// This class does not need to be modified.
UINTERFACE()
class UPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPS_API IPlayerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetWeaponAttachPoint(const FGameplayTag& WeaponType) const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USkeletalMeshComponent* GetMesh1P() const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USkeletalMeshComponent* GetMesh3P() const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void WeaponReplicated();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AWeapon* GetCurrentWeapon();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetReserveAmmo() const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Notify_CycleWeapon();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Notify_ReloadWeapon();
};
