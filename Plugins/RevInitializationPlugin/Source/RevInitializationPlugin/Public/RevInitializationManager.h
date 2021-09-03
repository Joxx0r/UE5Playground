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

	/** Initializes the manager to refresh state at a given frequency.*/
	void Initialize(float refreshFrequency);

	/** Requests an initialization to be callbacked. */
	static int32 RequestCompleteInitializationCallback(	AActor* actorContext,const FYInitializationCompleteDelegate& delegate, ERevInitializationRequestSettingTypes type = ERevInitializationRequestSettingTypes::AllComplete);

	UFUNCTION(BlueprintCallable)
	static int32 RequestCompleteInitializationCallbackBlueprint(AActor* actorContext, UPARAM(DisplayName = "Event") FYInitializationCompleteDelegateDynamic delegate, bool& outSuccess, ERevInitializationRequestSettingTypes type = ERevInitializationRequestSettingTypes::AllComplete);
	
protected:

	/** Updates the initialization manager with given delta seconds. */
	UFUNCTION()
	void Update();
	
	/** Defines the pending requests to initialize. */
	UPROPERTY()
	TMap<int32, FRevInitializationRequestEntry> m_requests;

	/** Defines the frequency of how often we check for initialization. */
	UPROPERTY()
	float m_checkInitializationStateFrequency = 0.0f;

	/** Defines the stored handle for timermanagement. */
	FTimerHandle m_initializationStateTimerHandle;
	
public:

	/** Returns debug state for the given initialization manager. */
	static FString GetDebugState(const UObject* objCtx);


};

