// Copyright Druid Mechanics


#include "UI/ShooterReticle.h"

#include "Character/ShooterCharacter.h"

void UShooterReticle::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	GetOwningPlayer()->OnPossessedPawnChanged.AddDynamic(this, &ThisClass::OnPossessedPawnChanged);
	
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(GetOwningPlayer()->GetPawn());
	if (!IsValid(ShooterCharacter)) return;
	
	OnPossessedPawnChanged(nullptr, ShooterCharacter);
	
	if (ShooterCharacter->HasWeaponFirstReplicated())
	{
		// Get Dynamic Material Instances from the Weapon.
	}
	else
	{
		ShooterCharacter->OnWeaponFirstReplicated.AddDynamic(this, &ThisClass::OnWeaponFirstReplicated);
	}
}

void UShooterReticle::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UShooterReticle::OnPossessedPawnChanged(APawn* OldPawn, APawn* NewPawn)
{
	// Unbind from delegates on the Old Pawn's Combat Component
	// Bind to delegates on the New Pawn's Combat Component
}

void UShooterReticle::OnWeaponFirstReplicated(AWeapon* Weapon)
{
	// Get Dynamic Material Instances from the Weapon.
}
