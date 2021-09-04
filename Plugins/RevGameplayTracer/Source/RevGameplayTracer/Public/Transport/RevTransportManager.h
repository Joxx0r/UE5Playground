#pragma once

#include "CoreMinimal.h"
#include "RevTransportTypes.h"
#include "RevTransportManager.generated.h"

UCLASS(config=Game)
class REVGAMEPLAYTRACER_API ARevTransportManager : public AActor
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static ARevTransportManager* FindTransportManager(const UObject* objCtx);
	
	UFUNCTION(BlueprintCallable)
	static int32 ExecuteTransport(const UObject* objCtx, const FYTransportInitializationData& initializationData);
	
};

