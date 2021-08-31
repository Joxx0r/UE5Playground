#include "Core/Player/RevPlayerController.h"
#include "Core/Player/RevControllerInputComponent.h"
#include "Game/GAAS/RevControllerAbilityComponent.h"
#include "Core/RevLogCategories.h"

ARevPlayerController::ARevPlayerController()
{
	CreateDefaultSubobject<UYRevControllerAbilityComponent>(TEXT("ControllerAbilityGAASComponent"));	
	CreateDefaultSubobject<UYRevControllerInputComponent>(TEXT("ControllerInputComponent"));	
}

void ARevPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	if(UYRevControllerInputComponent* Component = Cast<UYRevControllerInputComponent>(GetComponentByClass(UYRevControllerInputComponent::StaticClass())))
	{
		InputComponent->BindAction("Jump", IE_Pressed, Component,  &UYRevControllerInputComponent::OnInputOneClicked);
	}
	else
	{
		UE_LOG(LogRevPlayer, Error, TEXT("SetupInputComponent | Failed finding the input controller component to bind proper input towards"));
	}
}
