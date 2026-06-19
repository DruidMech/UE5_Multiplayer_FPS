// Copyright Druid Mechanics


#include "Combat/CombatComponent.h"


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	
}



void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UCombatComponent::Initiate_CycleWeapon()
{
}

void UCombatComponent::Initiate_FireWeapon_Pressed()
{
}

void UCombatComponent::Initiate_FireWeapon_Released()
{
}

void UCombatComponent::Initiate_ReloadWeapon()
{
}

void UCombatComponent::Initiate_Aim_Pressed()
{
}

void UCombatComponent::Initiate_Aim_Released()
{
}

