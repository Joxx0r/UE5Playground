// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/UE5PlaygroundGameMode.h"
#include "Core/UE5PlaygroundCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5PlaygroundGameMode::AUE5PlaygroundGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
