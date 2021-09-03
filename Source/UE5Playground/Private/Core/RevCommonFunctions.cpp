#include "Core/RevCommonFunctions.h"
#include "Core/RevEngineFunctions.h"
#include "Core/RevGameInstance.h"
#include "Engine/DataTable.h"

bool URevCommonFunctions::FindPlayerTuning(const UObject* objCtx, FRevPlayerTuning& outTuning)
{
	FRevPlayerTuning* tuning = FindRawPlayerTuning(objCtx);
	if(!tuning)
	{
		return false;
	}

	outTuning = *tuning;
	return true;
}

URevGameInstance* URevCommonFunctions::FindRevGameInstance(const UObject* objCtx)
{
	return Cast<URevGameInstance>(URevEngineFunctions::FindGameInstanceFromContextObject(objCtx));
}

FRevPlayerTuning* URevCommonFunctions::FindRawPlayerTuning(const UObject* objCtx)
{
	URevGameInstance* revInstance = FindRevGameInstance(objCtx);
	if(!revInstance || !revInstance->m_playerTuningDT)
	{
		return nullptr;
	}

	TArray<FRevPlayerTuning*> tunings;
	revInstance->m_playerTuningDT->GetAllRows(TEXT("FindRawPlayerTuning"), tunings);
	if(tunings.Num() > 0)
	{
		return tunings[0];
	}
	return nullptr;
}

URevPlayerInitializationDA* URevCommonFunctions::FindPlayerInitializationDataAsset(const UObject* objCtx)
{
	URevGameInstance* revInstance = FindRevGameInstance(objCtx);
	if(!revInstance || !revInstance->m_playerTuningDTAsset)
	{
		return nullptr;
	}
	return revInstance->m_playerInitializationDAAsset;
}

URevCharacterDA* URevCommonFunctions::FindPlayerAnimationDA(const UObject* objCtx)
{
	URevPlayerInitializationDA* daInit = FindPlayerInitializationDataAsset(objCtx);
	if(!daInit)
	{
		return nullptr;
	}
	return daInit->m_characterDA;
}

