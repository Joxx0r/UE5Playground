#pragma once

#include "CoreMinimal.h"
#include "Player/RevPlayerTypes.h"
#include "RevCommonFunctions.generated.h"

class URevGameInstance;

UCLASS()
class URevCommonFunctions : public UObject
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static bool FindPlayerTuning(const UObject* objCtx, FRevPlayerTuning& outTuning);

	static FRevPlayerTuning* FindRawPlayerTuning(const UObject* objCtx);

	UFUNCTION(BlueprintPure)
	static URevGameInstance* FindRevGameInstance(const UObject* objCtx);
	
};

