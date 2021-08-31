#pragma once

#include "Components/ActorComponent.h"
#include "RevControllerInputComponent.generated.h"

UCLASS()
class UYRevControllerInputComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnInputOneClicked();
};