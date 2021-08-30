#pragma once

#include "CoreMinimal.h"
#include "RevEngineFunctions.generated.h"

class URevGameInstance;

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class URevEngineFunctions : public UObject
{
	
public:
	GENERATED_BODY()
	
	static URevGameInstance* FindGameInstanceFromContextObject(const UObject* objCtx);
};

