#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RevGameInstance.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class URevGameInstance : public UGameInstance
{
public:
	GENERATED_BODY()

	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TAssetPtr<UDataTable> m_playerTuningDTAsset;

	UPROPERTY()
	UDataTable* m_playerTuningDT;
};