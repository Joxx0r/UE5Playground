#pragma once

#include "CoreMinimal.h"
#include "RevInitializationRetrievalInterface.h"
#include "Engine/DataTable.h"
#include "Core/Player/RevPlayerTypes.h"
#include "RevGameInstance.generated.h"

class URevPlayerInitializationDA;
class URevInitializationManager;

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class URevGameInstance : public UGameInstance, public IRevInitializationRetrievalInterface
{
public:
	GENERATED_BODY()

	URevGameInstance();

	virtual void Init() override;

	virtual URevInitializationManager* GetInitializationManager() const override;
	
	virtual bool IsAdditionalInitializationComplete(const FRevInitializationContext& relevantContext, ERevInitializationRequestSettingTypes type) const override;

	virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UDataTable> m_playerTuningDTAsset;

	UPROPERTY()
	UDataTable* m_playerTuningDT;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<URevPlayerInitializationDA> m_playerinitializationDAAssetSoft;
	UPROPERTY()
	URevPlayerInitializationDA* m_playerInitializationDAAsset;

	UPROPERTY()
	URevInitializationManager* m_initManager;
};