// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/RevBaseGameMode.h"
#include "Core/RevPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARevBaseGameMode::ARevBaseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
}