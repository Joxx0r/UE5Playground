#include "Core/Player/RevPlayerCheatManager.h"
#include "Impact/RevImpactManager.h"
#include "Impact/RevImpactTypes.h"
#include "Transport/RevTransportManager.h"

void URevCheatManager::RevDebugExecuteTransport()
{
	FYTransportInitializationData initData = {};
	ARevTransportManager::ExecuteTransport(GetOuterAPlayerController(), initData);
}

void URevCheatManager::RevDebugExecuteImpact()
{
	FYImpactInitializationData initData = {};
	ARevImpactManager::ExecuteImpact(GetOuterAPlayerController(), initData);
}
