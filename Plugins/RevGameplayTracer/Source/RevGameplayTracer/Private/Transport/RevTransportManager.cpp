#include "Transport/RevTransportManager.h"
#include "Misc/RevGameplayTracerRetrievalInterface.h"
#include "GameFramework/GameStateBase.h"

ARevTransportManager* ARevTransportManager::FindTransportManager(const UObject* objCtx)
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
	
	return interface->GetTransportManager();
}

int32 ARevTransportManager::ExecuteTransport(const UObject* objCtx, const FYTransportInitializationData& initializationData)
{
	ARevTransportManager* manager = FindTransportManager(objCtx);
	if(manager)
	{
		//do stuff
	}
	return INDEX_NONE;
}
