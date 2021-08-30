#include "Core/Player/RevPlayerController.h"
#include "Game/GAAS/RevControllerAbilityComponent.h"

ARevPlayerController::ARevPlayerController()
{
	CreateDefaultSubobject<
		UYRevControllerAbilityComponent>(TEXT("ARevPlayerController"));	
}
