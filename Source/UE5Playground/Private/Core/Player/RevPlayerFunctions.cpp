#include "Core/Player/RevPlayerFunctions.h"

#include "Core/RevCommonFunctions.h"

bool URevPlayerFunctions::FindAnimationDataForAsset(const UObject* objCtx, ERevAnimationType type, FRevPlayerGameplayAnimationData& outData)
{
	if(URevCharacterDA* characterDa = URevCommonFunctions::FindPlayerAnimationDA(objCtx))
	{
		if(FRevPlayerGameplayAnimationData* animData = characterDa->m_gameplayToAnimationData.Find(type))
		{
			outData	= *animData;
			return true;
		}
	}
	
	return false;
}
