#include "Game/GAAS/RevControllerAbilityComponent.h"

#include "RevInitializationManager.h"
#include "Core/RevCommonFunctions.h"
#include "Core/RevGameInstance.h"
#include "GameFramework/Pawn.h"
#include "Game/GAAS/RevAbilitySystemComponent.h"
#include "Core/RevCommonFunctions.h"
#include "Core/RevCommonTemplates.h"

void UYRevControllerAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	auto OnCompleted = [this](const FRevInitializationContext& context)
	{
		if(GetOwnerRole() != ROLE_Authority)
		{
			return;
		}
		if(context.m_pawn)
		{
			if(UYRevAbilitySystemComponent* RevAbilitySystemComponent = RevTemplateFunctions::FindActorComponent<UYRevAbilitySystemComponent>(context.m_pawn))
			{
				FGameplayAbilitySpec Spec = {};
				if(URevGameInstance* Instance = URevCommonFunctions::FindRevGameInstance(context.m_pawn))
				{
					for (auto Ability : Instance->m_abilitiesInitDA->m_initialAbilities)
					{
						RevAbilitySystemComponent->GiveAbility(Ability);
					}
				}
			};
		}
	};
	URevInitializationManager::RequestCompleteInitializationCallback(GetOwner(),FYInitializationCompleteDelegate::CreateWeakLambda(this, OnCompleted));
}

