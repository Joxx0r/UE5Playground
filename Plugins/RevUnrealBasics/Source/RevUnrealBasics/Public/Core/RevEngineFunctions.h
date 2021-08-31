#pragma once

#include "CoreMinimal.h"
#include "RevEngineFunctions.generated.h"

class URevGameInstance;

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class REVUNREALBASICS_API URevEngineFunctions : public UObject
{
	
public:
	GENERATED_BODY()
	
	static UGameInstance* FindGameInstanceFromContextObject(const UObject* objCtx);
	static const UGameInstance* FindGameInstanceFromContextObjectConst(const UObject* objCtx);
	
	static const APawn* FindPawnFromContextObjectConst(const UObject* objCtx);
	static APawn* FindPawnFromContextObject(const UObject* objCtx);
	
	static const ACharacter* FindCharacterFromContextObjectConst(const UObject* objCtx);
	static ACharacter* FindCharacterFromContextObject(const UObject* objCtx);
};

