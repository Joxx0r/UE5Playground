#pragma once


#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "RevGameplayEffectDamageCalculation.generated.h"

/**
* A damage execution, which allows doing damage by combining a raw Damage number with AttackPower and DefensePower
* Most games will want to implement multiple game-specific executions
*/
UCLASS()
class URevGameplayEffectDamageCalculcation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

	public:
	// Constructor and overrides
	URevGameplayEffectDamageCalculcation();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

};

