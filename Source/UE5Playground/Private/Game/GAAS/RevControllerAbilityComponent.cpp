#include "Game/GAAS/RevControllerAbilityComponent.h"

void UYRevControllerAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if(GetOwnerRole() == Role_Authorithy())
	{
	   if(URevGameInstance* instance = URevCommonFunctions::FindRevGameInstance(GetOwner()))
	   {
	       instance->
	   }
	}
	
	
}

