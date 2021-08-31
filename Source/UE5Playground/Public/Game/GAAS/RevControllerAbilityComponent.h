#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "RevControllerAbilityComponent.generated.h"

UCLASS()
class UYRevControllerAbilityComponent : public UActorComponent
{
public:
	
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> m_specHandles;
	
};

