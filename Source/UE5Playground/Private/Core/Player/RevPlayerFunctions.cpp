#include "Core/Player/RevPlayerFunctions.h"
#include "Core/RevCommonFunctions.h"
#include "Core/RevEngineFunctions.h"

bool URevPlayerFunctions::FindAnimationDataForAsset(const UObject* objCtx, ERevAnimationType type, FRevPlayerGameplayAnimationData& outData)
{
	if(URevCharacterDA* characterDa = URevCommonFunctions::FindPlayerAnimationDA(objCtx))
	{
		if(const FRevPlayerGameplayAnimationData* animData = characterDa->m_gameplayToAnimationData.Find(type))
		{
			outData	= *animData;
			return true;
		}
	}
	
	return false;
}

bool URevPlayerFunctions::FindRelevantPlayerViewLocationRotation(const UObject* objCtx, bool useLocal, FVector& outLocation, FRotator& outRotation)
{
	if(const APlayerController* ctrl = URevEngineFunctions::FindPlayerControllerFromContextObjectConst(objCtx, useLocal))
	{
		ctrl->GetPlayerViewPoint(outLocation, outRotation);
		return true;
	}
	return false;
}

