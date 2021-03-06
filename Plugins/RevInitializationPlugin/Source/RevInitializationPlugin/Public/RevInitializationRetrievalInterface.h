#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RevInitializationTypes.h"
#include "RevInitializationRetrievalInterface.generated.h"

class URevInitializationManager;

UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class REVINITIALIZATIONPLUGIN_API URevInitializationRetrievalInterface : public UInterface
{
	GENERATED_BODY()
};

class REVINITIALIZATIONPLUGIN_API IRevInitializationRetrievalInterface
{
	GENERATED_BODY()

public:
	
	virtual URevInitializationManager* GetInitializationManager() const = 0;
	virtual bool IsAdditionalInitializationComplete(const FRevInitializationContext& relevantContext, ERevInitializationRequestSettingTypes type) const = 0;
};
