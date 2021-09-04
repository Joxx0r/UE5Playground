#include "Core/RevEngineFunctions.h"
#include "GameFramework/Character.h"


const UGameInstance* URevEngineFunctions::FindGameInstanceFromContextObjectConst(const UObject* objCtx)
{
	UWorld* world = GEngine->GetWorldFromContextObject(objCtx, EGetWorldErrorMode::LogAndReturnNull);
	if(!world)
	{
		return nullptr;
	}

	return world->GetGameInstance();
}

UGameInstance* URevEngineFunctions::FindGameInstanceFromContextObject(const UObject* objCtx)
{
	return const_cast<UGameInstance*>(FindGameInstanceFromContextObjectConst(objCtx));
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

const APlayerController* URevEngineFunctions::FindLocalPlayerControllerFromContextObjectConst(const UObject* objCtx)
{
	UWorld* world = objCtx->GetWorld();
	check(world);
	if(world->IsNetMode(NM_DedicatedServer))
	{
		return nullptr;
	}
	return world->GetFirstPlayerController();
}

APlayerController* URevEngineFunctions::FindLocalPlayerControllerFromContextObject(const UObject* objCtx)
{
	return const_cast<APlayerController*>(Cast<APlayerController>(FindLocalPlayerControllerFromContextObjectConst(objCtx)));
}

const APlayerController* URevEngineFunctions::FindPlayerControllerFromContextObjectConst(const UObject* objCtx, bool useLocal /*= true*/)
{
	if(const APawn* pawn = Cast<APawn>(objCtx))
	{
		AController* pawnController = pawn->GetController();
		if(pawnController != nullptr && pawnController->IsA<APlayerController>())
		{
			return Cast<APlayerController>(pawnController);
		}
	}
	if(const UActorComponent* component = Cast<UActorComponent>(objCtx))
	{
		return FindPlayerControllerFromContextObjectConst(component->GetOwner(), useLocal);
	}
	if(const AController* controller = Cast<AController>(objCtx))
	{
		if(controller != nullptr && controller->IsA<APlayerController>())
		{
			return Cast<APlayerController>(controller);
		}
	}
	if(useLocal)
	{
		return FindLocalPlayerControllerFromContextObjectConst(objCtx);	
	}
	
	return nullptr;
}

APlayerController* URevEngineFunctions::FindPlayerControllerFromContextObject(const UObject* objCtx, bool useLocal /*= true*/)
{
	return const_cast<APlayerController*>(Cast<APlayerController>(FindPlayerControllerFromContextObjectConst(objCtx, useLocal)));	
}
