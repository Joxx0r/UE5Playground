#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RevBaseGameState.generated.h"

UCLASS(minimalapi)
class ARevBaseGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ARevBaseGameState();

	virtual void PostInitializeComponents() override;

	virtual void Update();

	FTimerHandle m_updateTime;
};


