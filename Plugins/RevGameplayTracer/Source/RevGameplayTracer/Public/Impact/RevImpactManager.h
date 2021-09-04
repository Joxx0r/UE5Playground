#pragma once

#include "CoreMinimal.h"
#include "RevImpactTypes.h"
#include "RevImpactManager.generated.h"

UCLASS(config=Game)
class REVGAMEPLAYTRACER_API ARevImpactManager : public AActor
{
	
public:
	
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static ARevImpactManager* FindImpactManager(const UObject* objCtx);
	
	UFUNCTION(BlueprintCallable)
	static int32 ExecuteImpact(const UObject* objCtx, const FYImpactInitializationData& initializationData);
	
};