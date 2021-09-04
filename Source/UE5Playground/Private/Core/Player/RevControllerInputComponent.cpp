#include "Core/Player/RevControllerInputComponent.h"
#include "Game/GAAS/RevAbilitySystemComponent.h"
#include "Game/GAAS/Functions/RevAbilitySystemBaseFunctions.h"

void UYRevControllerInputComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UYRevControllerInputComponent::OnInputOneClicked(int32 inputClicked)
{
	if(URevAbilitySystemComponent* component = UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActor(GetOwner()))
	{
		component->TryActivateAbility(UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActor(GetOwner(), inputClicked));
	}
}

void UYRevControllerInputComponent::OnLeftMouseClick()
{
	if(URevAbilitySystemComponent* component = UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActor(GetOwner()))
	{
		component->TryActivateAbility(UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActor(GetOwner(), 0));
	}
	
}

