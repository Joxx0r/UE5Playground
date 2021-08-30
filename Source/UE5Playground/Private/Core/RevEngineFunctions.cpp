#include "Core/RevEngineFunctions.h"
#include "Core/RevGameInstance.h"

URevGameInstance* URevEngineFunctions::FindGameInstanceFromContextObject(const UObject* objCtx)
{
	UWorld* world = GEngine->GetWorldFromContextObject(objCtx, EGetWorldErrorMode::LogAndReturnNull);
	if(!world)
	{
		return nullptr;
	}

	return Cast<URevGameInstance>(world->GetGameInstance());
}
