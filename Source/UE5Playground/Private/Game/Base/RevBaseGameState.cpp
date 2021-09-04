#include "Game/Base/RevBaseGameState.h"
#include "Impact/RevImpactManager.h"
#include "Transport/RevTransportManager.h"

ARevBaseGameState::ARevBaseGameState()
{
}

void ARevBaseGameState::BeginPlay()
{
    Super::BeginPlay();

    {
        FActorSpawnParameters Parameters = {};
        Parameters.Owner = this;
        m_transportManager = GetWorld()->SpawnActor<ARevTransportManager>(Parameters);
        m_impactManager = GetWorld()->SpawnActor<ARevImpactManager>(Parameters);
    }
}

