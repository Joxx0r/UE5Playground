#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RevGameplayTracerRetrievalInterface.generated.h"

class ARevTransportManager;
class ARevImpactManager;

UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class REVGAMEPLAYTRACER_API URevGameplayTracerRetrievalInterface : public UInterface
{
	GENERATED_BODY()
};

class REVGAMEPLAYTRACER_API IRevGameplayTracerRetrievalInterface
{
	GENERATED_BODY()

public:
	virtual ARevTransportManager* GetTransportManager() const = 0;
	virtual ARevImpactManager* GetImpactManager() const = 0;
};
