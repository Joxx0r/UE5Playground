#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Misc/RevGameplayTracerRetrievalInterface.h"
#include "RevBaseGameState.generated.h"

class ARevImpactManager;
class ARevTransportManager;

UCLASS(minimalapi)
class ARevBaseGameState : public AGameStateBase, public IRevGameplayTracerRetrievalInterface
{
	GENERATED_BODY()

public:
	ARevBaseGameState();
	
	virtual void BeginPlay() override;

	virtual ARevImpactManager* GetImpactManager() const override{ return m_impactManager; }
	virtual ARevTransportManager* GetTransportManager() const override { return m_transportManager; }

protected:

	UPROPERTY()
	ARevTransportManager* m_transportManager;
	UPROPERTY()
	ARevImpactManager* m_impactManager;

};


