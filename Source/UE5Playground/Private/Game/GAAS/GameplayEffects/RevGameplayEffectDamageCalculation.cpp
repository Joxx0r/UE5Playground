#include "Game/GAAS/GameplayEffects/RevGameplayEffectDamageCalculation.h"
#include "Game/GAAS/AttributeSets/RevAttributeCoreSet.h"

struct RevDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	RevDamageStatics()
	{
		// Also capture the source's raw Damage, which is normally passed in directly via the execution
		DEFINE_ATTRIBUTE_CAPTUREDEF(URevAttributeCoreSet, Damage, Source, true);
	}
};

static const RevDamageStatics& DamageStatics()
{
	static RevDamageStatics DmgStatics;
	return DmgStatics;
}

URevGameplayEffectDamageCalculcation::URevGameplayEffectDamageCalculcation()
{
	RelevantAttributesToCapture.Add(RevDamageStatics().DamageDef);
}

void URevGameplayEffectDamageCalculcation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	// Gather the tags from the source and target as that can affect which buffs should be used
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluationParameters, Damage);
	if (Damage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, Damage));
	}
}
