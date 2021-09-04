#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Game/GAAS/Misc/RevAbilityTypes.h"
#include "RevAbilityTargetType.generated.h"

class AActor;
struct FGameplayEventData;


UCLASS(Blueprintable, meta = (ShowWorldContextPin))
class URevTargetType : public UObject
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URevTargetType() {}

	/** Called to determine targets to apply gameplay effects to */
	UFUNCTION(BlueprintNativeEvent)
	void GetTargets(APawn* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const;
};

UCLASS(NotBlueprintable)
class URevTargetTypeUseOwner : public URevTargetType
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URevTargetTypeUseOwner() {}

	/** Uses the passed in event data */
	virtual void GetTargets_Implementation(APawn* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};

UCLASS(NotBlueprintable)
class URevTargetTypeUseEventData : public URevTargetType
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URevTargetTypeUseEventData() {}

	/** Uses the passed in event data */
	virtual void GetTargets_Implementation(APawn* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};
