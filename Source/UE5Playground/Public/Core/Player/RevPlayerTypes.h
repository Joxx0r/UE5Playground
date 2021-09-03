#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Core/RevTableRowBase.h"
#include "RevPlayerTypes.generated.h"

UENUM(BlueprintType)
enum class ERevAnimationType : uint8
{
	Dodge
};

USTRUCT(BlueprintType)
struct FRevPlayerGameplayAnimationData 
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* m_animationMontage;
};

USTRUCT()
struct FRevPlayerTuning : public FRevTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Camera")
	float m_cameraDistance;
};


UCLASS()
class URevCharacterDA : public UPrimaryDataAsset
{
public:
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,  Category="Animation")
	USkeletalMesh* m_meshToUse;
	
	UPROPERTY(EditDefaultsOnly,  BlueprintReadOnly, Category="Animation")
	UClass* m_animInstanceClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation")
	TMap<ERevAnimationType, FRevPlayerGameplayAnimationData> m_gameplayToAnimationData;
};

UCLASS()
class URevPlayerInitializationDA : public UPrimaryDataAsset
{
public:
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> m_initialAbilities;

	UPROPERTY(EditDefaultsOnly,  BlueprintReadOnly, Category="Animation")
	TObjectPtr<URevCharacterDA> m_characterDA;
};

