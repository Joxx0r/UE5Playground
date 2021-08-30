#pragma once

#include "CoreMinimal.h"
#include "Player/RevPlayerTypes.h"
#include "RevCommonFunctions.generated.h"

UCLASS()
class URevCommonFunctions : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static bool FindPlayerTuning(const UObject* objCtx, FRevPlayerTuning& outTuning);

	static FRevPlayerTuning* FindRawPlayerTuning(const UObject* objCtx);
	
};

