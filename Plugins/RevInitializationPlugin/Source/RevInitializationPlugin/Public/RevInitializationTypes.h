#pragma once

#include "CoreMinimal.h"
#include "RevInitializationTypes.generated.h"

class IRevInitializationRetrievalInterface;
class APlayerState;
class AActor;

UENUM(BlueprintType)
enum class ERevInitializationRequestSettingTypes : uint8
{
	Invalid,
	AllComplete,
	IgnoreCharacterCustomization
};
	

USTRUCT(BlueprintType)
struct REVINITIALIZATIONPLUGIN_API FRevInitializationContext
{
	GENERATED_BODY()

	FRevInitializationContext() {};
	FRevInitializationContext(AActor* actorContext, ERevInitializationRequestSettingTypes type, IRevInitializationRetrievalInterface* initInterface);

	/** Returns string entry of a given context. */
	FString ToString() const;
	bool IsValid() const;
	
	/** Defines the initial initialization contests. */
	UPROPERTY(BlueprintReadOnly)
	APlayerController* m_controller = nullptr;
	UPROPERTY(BlueprintReadOnly)
	APlayerState* m_playerState = nullptr;
	UPROPERTY(BlueprintReadOnly)
	APawn* m_pawn = nullptr; 
	UPROPERTY(BlueprintReadOnly)
	FString m_userId = FString(); 
	UPROPERTY(BlueprintReadOnly)
	bool m_isAdditionalIntialized = false;
	UPROPERTY(BlueprintReadOnly)
	ERevInitializationRequestSettingTypes m_requestSettingType;
	
};


DECLARE_DELEGATE_OneParam(FYInitializationCompleteDelegate, const FRevInitializationContext&);
DECLARE_DYNAMIC_DELEGATE_OneParam(FYInitializationCompleteDelegateDynamic, const FRevInitializationContext&, result);

/** Defines a request entry when initialization is complete */
USTRUCT(BlueprintType)
struct REVINITIALIZATIONPLUGIN_API FRevInitializationRequestEntry
{
	GENERATED_BODY()

	UPROPERTY()
	AActor* m_relevantContext;

	FYInitializationCompleteDelegate m_delegate;

	UPROPERTY()
	FYInitializationCompleteDelegateDynamic m_bpDelegate;
	
	UPROPERTY()
	ERevInitializationRequestSettingTypes m_requestType = ERevInitializationRequestSettingTypes::AllComplete;;

};
