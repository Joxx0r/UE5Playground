#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "RevPlayerCheatManager.generated.h"

UCLASS(Blueprintable, Within=PlayerController)
class URevCheatManager : public UCheatManager
{
	GENERATED_BODY()

	UFUNCTION(exec)
	void RevDebugExecuteTransport();
	
};

