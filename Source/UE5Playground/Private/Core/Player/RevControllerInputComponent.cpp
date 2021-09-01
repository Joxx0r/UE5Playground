#include "Core/Player/RevControllerInputComponent.h"
#include "Game/GAAS/RevAbilitySystemComponent.h"
#include "Game/GAAS/Functions/RevAbilitySystemBaseFunctions.h"

void UYRevControllerInputComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UYRevControllerInputComponent::OnInputOneClicked()
{
	if(UYRevAbilitySystemComponent* component = UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActor(GetOwner()))
	{
		component->TryActivateAbility(UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActor(GetOwner(), 0));
	}
}

void UYRevControllerInputComponent::OnInputTwoClicked()
{
	if(UYRevAbilitySystemComponent* component = UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActor(GetOwner()))
	{
		component->TryActivateAbility(UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActor(GetOwner(), 1));
	}
}
