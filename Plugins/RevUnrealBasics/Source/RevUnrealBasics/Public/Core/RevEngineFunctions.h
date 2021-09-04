#pragma once

#include "CoreMinimal.h"
#include "RevEngineFunctions.generated.h"

class URevGameInstance;

UCLASS(Blueprintable, BlueprintType, ClassGroup=Mobile)
class REVUNREALBASICS_API URevEngineFunctions : public UObject
{
	
public:
	GENERATED_BODY()
	
	static const UGameInstance* FindGameInstanceFromContextObjectConst(const UObject* objCtx);
	static UGameInstance* FindGameInstanceFromContextObject(const UObject* objCtx);
	
	static const APawn* FindPawnFromContextObjectConst(const UObject* objCtx);
	static APawn* FindPawnFromContextObject(const UObject* objCtx);
	
	static const ACharacter* FindCharacterFromContextObjectConst(const UObject* objCtx);
	static ACharacter* FindCharacterFromContextObject(const UObject* objCtx);
	
	static const APlayerController* FindLocalPlayerControllerFromContextObjectConst(const UObject* objCtx);
	static APlayerController* FindLocalPlayerControllerFromContextObject(const UObject* objCtx);
	
	static const APlayerController* FindPlayerControllerFromContextObjectConst(const UObject* objCtx, bool useLocal = true);
	static APlayerController* FindPlayerControllerFromContextObject(const UObject* objCtx, bool useLocal = true);
};

