#include "Core/RevEngineFunctions.h"
#include "GameFramework/Character.h"

UGameInstance* URevEngineFunctions::FindGameInstanceFromContextObject(const UObject* objCtx)
{
	UWorld* world = GEngine->GetWorldFromContextObject(objCtx, EGetWorldErrorMode::LogAndReturnNull);
	if(!world)
	{
		return nullptr;
	}

	return world->GetGameInstance();
}

const UGameInstance* URevEngineFunctions::FindGameInstanceFromContextObjectConst(const UObject* objCtx)
{
	return FindGameInstanceFromContextObject(objCtx);
}

const APawn* URevEngineFunctions::FindPawnFromContextObjectConst(const UObject* objCtx)
{
	if(const APawn* pawn = Cast<APawn>(objCtx))
	{
		return pawn;
	}

	if(const UActorComponent* component = Cast<UActorComponent>(objCtx))
	{
		return FindPawnFromContextObjectConst(component->GetOwner());
	}
	
	if(const AController* controller = Cast<AController>(objCtx))
	{
		return controller->GetPawn();
	}
	return nullptr;
}

APawn* URevEngineFunctions::FindPawnFromContextObject(const UObject* objCtx)
{
	return const_cast<APawn*>(FindPawnFromContextObjectConst(objCtx));
}

const ACharacter* URevEngineFunctions::FindCharacterFromContextObjectConst(const UObject* objCtx)
{
	return Cast<ACharacter>(FindPawnFromContextObjectConst(objCtx));
}

ACharacter* URevEngineFunctions::FindCharacterFromContextObject(const UObject* objCtx)
{
	return const_cast<ACharacter*>(Cast<ACharacter>(FindCharacterFromContextObjectConst(objCtx)));
}
