#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RevPlayerController.generated.h"


UCLASS(config=Game)
class ARevPlayerController : public APlayerController
{
	GENERATED_BODY()

	ARevPlayerController();

	virtual void SetupInputComponent() override;

};