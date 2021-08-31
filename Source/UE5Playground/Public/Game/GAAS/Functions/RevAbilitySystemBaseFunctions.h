#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "RevAbilitySystemBaseFunctions.generated.h"

class UYRevControllerAbilityComponent;
class UYRevAbilitySystemComponent;

UCLASS()
class UYRevAbilitySystemBaseFunctions : public UObject
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static UYRevAbilitySystemComponent* FindAbilitySystemComponentFromActor(const AActor* actCtx);
	UFUNCTION(BlueprintCallable)
	static const UYRevAbilitySystemComponent* FindAbilitySystemComponentFromActorConst(const AActor* actCtx);

	UFUNCTION(BlueprintCallable)
	static UYRevControllerAbilityComponent* FindControllerAbilityComponent(const AActor* actCtx);
	UFUNCTION(BlueprintCallable)
	static const UYRevControllerAbilityComponent* FindControllerAbilityComponentConst(const AActor* actCtx);
	
	UFUNCTION(BlueprintCallable)
	static bool FindAbilitySpecHandleByIndexFromActorBlueprint(const AActor* actCtx, int32 index, FGameplayAbilitySpecHandle& outHandle);
	static FGameplayAbilitySpecHandle FindAbilitySpecHandleByIndexFromActor(const AActor* actCtx, int32 index);
};


