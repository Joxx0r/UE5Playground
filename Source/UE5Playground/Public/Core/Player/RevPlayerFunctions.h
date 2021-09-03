#pragma once

#include "CoreMinimal.h"
#include "RevPlayerTypes.h"
#include "RevPlayerFunctions.generated.h"

UCLASS()
class URevPlayerFunctions : public UObject
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static bool FindAnimationDataForAsset(const UObject* objCtx, ERevAnimationType type, FRevPlayerGameplayAnimationData& outData); 
};

