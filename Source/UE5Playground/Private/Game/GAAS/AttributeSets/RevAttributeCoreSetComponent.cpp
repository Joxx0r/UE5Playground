#include "Game/GAAS/AttributeSets/RevAttributeCoreSetComponent.h"
#include "Game/GAAS/AttributeSets/RevAttributeCoreSet.h"

URevAttributeCoreSetComponent::URevAttributeCoreSetComponent()
{
	// Create the attribute set, this replicates by default
	AttributeSet = CreateDefaultSubobject<URevAttributeCoreSet>(TEXT("AttributeSet"));
}

void URevAttributeCoreSetComponent::HandleDamage(float DamageAmount, const FHitResult& HitInfo, const FGameplayTagContainer& DamageTags, APawn* InstigatorCharacter, AActor* DamageCauser)
{
}

void URevAttributeCoreSetComponent::HandleHealthChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
}

void URevAttributeCoreSetComponent::HandleManaChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
}

void URevAttributeCoreSetComponent::HandleMoveSpeedChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
}

float URevAttributeCoreSetComponent::GetHealth() const
{
	return AttributeSet->GetHealth();
}
float URevAttributeCoreSetComponent::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}
float URevAttributeCoreSetComponent::GetMana() const
{
	return AttributeSet->GetMana();
}
float URevAttributeCoreSetComponent::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}
float URevAttributeCoreSetComponent::GetMoveSpeed() const
{
	return AttributeSet->GetMoveSpeed();
}
