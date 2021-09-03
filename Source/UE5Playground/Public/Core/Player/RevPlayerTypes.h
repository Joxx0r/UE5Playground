#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Core/RevTableRowBase.h"
#include "RevPlayerTypes.generated.h"

USTRUCT()
struct FRevPlayerTuning : public FRevTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Camera")
	float m_cameraDistance;

};


UCLASS()
class URevPlayerInitializationDA : public UPrimaryDataAsset
{
public:
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> m_initialAbilities;

	
};

