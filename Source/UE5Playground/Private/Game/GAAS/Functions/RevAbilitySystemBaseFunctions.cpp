#include "Game/GAAS/Functions/RevAbilitySystemBaseFunctions.h"
#include "Core/RevCommonTemplates.h"
#include "Game/GAAS/RevControllerAbilityComponent.h"
#include "Game/GAAS/RevAbilitySystemComponent.h"

URevAbilitySystemComponent* UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActor(const AActor* actCtx)
{
	return RevTemplateFunctions::FindActorComponentControllerPawn<URevAbilitySystemComponent>(actCtx);
}

const URevAbilitySystemComponent* UYRevAbilitySystemBaseFunctions::FindAbilitySystemComponentFromActorConst(const AActor* actCtx)
{
	return RevTemplateFunctions::FindActorComponentControllerPawn<const URevAbilitySystemComponent>(actCtx);
}

UYRevControllerAbilityComponent* UYRevAbilitySystemBaseFunctions::FindControllerAbilityComponent(const AActor* actCtx)
{
	return RevTemplateFunctions::FindActorComponentControllerPawn<UYRevControllerAbilityComponent>(actCtx);
}

const UYRevControllerAbilityComponent* UYRevAbilitySystemBaseFunctions::FindControllerAbilityComponentConst(const AActor* actCtx)
{
	return RevTemplateFunctions::FindActorComponentControllerPawn<const UYRevControllerAbilityComponent>(actCtx);
}

FGameplayAbilitySpecHandle UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActor(const AActor* actCtx, int32 index)
{
	if(UYRevControllerAbilityComponent* component = FindControllerAbilityComponent(actCtx))
	{
		if(component->m_specHandles.IsValidIndex(index))
		{
			return component->m_specHandles[index];
		}
	}
	
	return FGameplayAbilitySpecHandle();
}

bool UYRevAbilitySystemBaseFunctions::FindAbilitySpecHandleByIndexFromActorBlueprint(const AActor* actCtx, int32 index, FGameplayAbilitySpecHandle& outHandle)
{
	outHandle = FindAbilitySpecHandleByIndexFromActor(actCtx, index);
	return outHandle.IsValid();
}
