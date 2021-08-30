#include "Game/Base/RevBaseGameState.h"
#include "RevInitializationManager.h"

ARevBaseGameState::ARevBaseGameState()
{
}

void ARevBaseGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	FTimerManager& TimerManager = GetWorldTimerManager();
	if (GetWorld()->IsGameWorld() && GetLocalRole() == ROLE_Authority)
	{
		TimerManager.SetTimer(m_updateTime, this, &ARevBaseGameState::Update, 1.0f, true);
	}
}

void ARevBaseGameState::Update()
{
	URevInitializationManager* manager = URevInitializationManager::FindInitializationManager (this);
	if(manager)
	{
		manager->Update(1.0f);
	}
}
