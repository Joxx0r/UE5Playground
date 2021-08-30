#pragma once

#include "CoreMinimal.h"
#include "Core/RevTableRowBase.h"
#include "RevPlayerTypes.generated.h"

USTRUCT()
struct FRevPlayerTuning : public FRevTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Camera")
	float m_cameraDistance;
};