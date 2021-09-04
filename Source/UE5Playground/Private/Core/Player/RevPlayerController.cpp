#include "Core/Player/RevPlayerController.h"
#include "Core/Player/RevControllerInputComponent.h"
#include "Game/GAAS/RevControllerAbilityComponent.h"
#include "Core/RevLogCategories.h"
#include "Core/RevCommonTemplates.h"
#include "Core/Player/RevPlayerCheatManager.h"

DECLARE_DELEGATE_OneParam(FInputActionHandlerSwitchWeapon, int32);

ARevPlayerController::ARevPlayerController()
{
	CreateDefaultSubobject<UYRevControllerAbilityComponent>(TEXT("ControllerAbilityGAASComponent"));	
	CreateDefaultSubobject<UYRevControllerInputComponent>(TEXT("ControllerInputComponent"));
	CheatClass = URevCheatManager::StaticClass();
}

void ARevPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	if(UYRevControllerInputComponent* Component = RevTemplateFunctions::FindActorComponent<UYRevControllerInputComponent>(this))
	{
		InputComponent->BindAction<FInputActionHandlerSwitchWeapon>("AbilityOne", IE_Pressed, Component,  &UYRevControllerInputComponent::OnInputOneClicked, 0);
		InputComponent->BindAction<FInputActionHandlerSwitchWeapon>("AbilityTwo", IE_Pressed, Component,  &UYRevControllerInputComponent::OnInputOneClicked, 1);
		InputComponent->BindAction("LeftMouseAction", IE_Pressed, Component,  &UYRevControllerInputComponent::OnLeftMouseClick);
	}
	else
	{
		UE_LOG(LogRevPlayer, Error, TEXT("SetupInputComponent | Failed finding the input controller component to bind proper input towards"));
	}
	
}
