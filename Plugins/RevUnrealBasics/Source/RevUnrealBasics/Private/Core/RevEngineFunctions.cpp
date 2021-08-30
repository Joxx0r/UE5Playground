#include "Core/RevEngineFunctions.h"

UGameInstance* URevEngineFunctions::FindGameInstanceFromContextObject(const UObject* objCtx)
{
	UWorld* world = GEngine->GetWorldFromContextObject(objCtx, EGetWorldErrorMode::LogAndReturnNull);
	if(!world)
	{
		return nullptr;
	}

	return world->GetGameInstance();
}
