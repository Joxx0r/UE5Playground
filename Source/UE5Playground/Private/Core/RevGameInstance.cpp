#include "Core/RevGameInstance.h"
#include "RevInitializationManager.h"
#include "Core/RevLogCategories.h"

URevGameInstance::URevGameInstance()
{
	m_initManager = CreateDefaultSubobject<URevInitializationManager>(TEXT("RevInitManager"));
}

void URevGameInstance::Init()
{
	Super::Init();
	
	m_playerTuningDT = m_playerTuningDTAsset.LoadSynchronous();
	if(!m_playerTuningDT)
	{
		UE_LOG(LogRevLoading, Error, TEXT("Failed loading the player tuning asset"));
	}

	m_abilitiesInitDA = m_abilitiesInitDAAsset.LoadSynchronous();
	if(!m_abilitiesInitDA)
	{
		UE_LOG(LogRevLoading, Error, TEXT("Failed loading the player DA asset"));
	}
}

URevInitializationManager* URevGameInstance::GetInitializationManager() const
{
	return m_initManager;
}

bool URevGameInstance::IsAdditionalInitializationComplete(const FRevInitializationContext& relevantContext, ERevInitializationRequestSettingTypes type) const
{
	return true;
}
void URevGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);
	//ensure to refresh it at world change.
	check(m_initManager);
	m_initManager->Initialize(0.5f);
}
