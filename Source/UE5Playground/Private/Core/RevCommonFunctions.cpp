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

FRevPlayerTuning* URevCommonFunctions::FindRawPlayerTuning(const UObject* objCtx)
{
	URevGameInstance* revInstance = Cast<URevGameInstance>(URevEngineFunctions::FindGameInstanceFromContextObject(objCtx));
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
