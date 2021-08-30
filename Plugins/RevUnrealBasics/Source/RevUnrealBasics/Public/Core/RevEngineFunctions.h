#pragma once

#include "CoreMinimal.h"
#include "RevEngineFunctions.generated.h"

class URevGameInstance;

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class REVUNREALBASICS_API URevEngineFunctions : public UObject
{
	
public:
	GENERATED_BODY()
	
	static UGameInstance* FindGameInstanceFromContextObject(const UObject* objCtx);
};

