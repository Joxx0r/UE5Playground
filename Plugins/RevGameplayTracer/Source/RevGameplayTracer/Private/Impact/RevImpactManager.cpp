#include "Impact/RevImpactManager.h"
#include "Misc/RevGameplayTracerRetrievalInterface.h"
#include "GameFramework/GameStateBase.h"

ARevImpactManager* ARevImpactManager::FindImpactManager(const UObject* objCtx)
{
	UWorld* world = objCtx ? objCtx->GetWorld() : nullptr;
    if (!world)
    {
    	return nullptr;
    }
    IRevGameplayTracerRetrievalInterface* interface = Cast<IRevGameplayTracerRetrievalInterface>( world->GetGameState());
    if(!interface)
    {
    	return nullptr;
    }
    return interface->GetImpactManager();
}

int32 ARevImpactManager::ExecuteImpact(const UObject* objCtx, const FYImpactInitializationData& initializationData)
{
	ARevImpactManager* manager = FindImpactManager(objCtx);
	if(manager)
	{
		//do stuff
	}
	return INDEX_NONE;
}
