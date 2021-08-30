#pragma once

#include "CoreMinimal.h"
#include "RevInitializationTypes.h"
#include "RevInitializationManager.generated.h"

UCLASS()
class REVINITIALIZATIONPLUGIN_API URevInitializationManager : public UObject
{
	GENERATED_BODY()

public:
	
	/** Returns a given intiailization manager. */
	static URevInitializationManager* FindInitializationManager(const UObject* objCtx);

	/** Updates the initialization manager with given delta seconds. */
	void Update(float deltaSeconds);

	/** Requests an initialization to be callbacked. */
	static int32 RequestCompleteInitializationCallback(	AActor* actorContext,const FYInitializationCompleteDelegate& delegate, ERevInitializationRequestSettingTypes type = ERevInitializationRequestSettingTypes::AllComplete);

	UFUNCTION(BlueprintCallable)
	static int32 RequestCompleteInitializationCallbackBlueprint(AActor* actorContext, UPARAM(DisplayName = "Event") FYInitializationCompleteDelegateDynamic delegate, bool& outSuccess, ERevInitializationRequestSettingTypes type = ERevInitializationRequestSettingTypes::AllComplete);
	
protected:

	/** Defines the pending requests to initialize. */
	UPROPERTY()
	TMap<int32, FRevInitializationRequestEntry> m_requests;

public:

	/** Returns debug state for the given initialization manager. */
	static FString GetDebugState(const UObject* objCtx);

};
