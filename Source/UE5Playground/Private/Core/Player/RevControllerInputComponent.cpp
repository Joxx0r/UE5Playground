#include "Core/Player/RevControllerInputComponent.h"
#include "Core/RevEngineFunctions.h"
#include "GameFramework/Character.h"

void UYRevControllerInputComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UYRevControllerInputComponent::OnInputOneClicked()
{
	if(ACharacter* character = URevEngineFunctions::FindCharacterFromContextObject(this))
	{
		character->Jump();
	}
}

