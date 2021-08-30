#include "Core/RevGameInstance.h"
#include "Core/RevLogCategories.h"

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
