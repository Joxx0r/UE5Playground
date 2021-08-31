#pragma once

#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"

class RevTemplateFunctions
{
public:
	template<class ComponentClass> static ComponentClass* FindActorComponent(const AActor* ThisActor);
	template<class ComponentClass> static ComponentClass* FindActorComponentRecursiveOwner(const AActor* ThisActor);
	template<class ComponentClass> static TArray<ComponentClass*> FindAllActorComponents(const AActor* thisActor);
	template<class ComponentClass> static ComponentClass* FindActorComponent(const UActorComponent* ThisComponent);
	template<class ComponentClass> static ComponentClass* FindActorComponentChecked(const AActor* ThisActor);
	template<class ComponentClass> static ComponentClass* FindActorComponentChecked(const UActorComponent* ThisComponent);
	template<class ComponentClass> static TArray<ComponentClass*> FindAllActorComponentsChecked(const AActor* thisActor);
	template<class ComponentClass> static ComponentClass* FindActorComponentControllerPawn(const AActor* ThisActor);
	template<class ComponentClass> static ComponentClass* FindActorComponentControllerState(const AActor* ThisActor);	
};

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponent(const AActor *ThisActor)
{
	if (ThisActor)
	{
		return ThisActor->FindComponentByClass<ComponentClass>();
	}
	
	return nullptr;
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponentRecursiveOwner(const AActor* ThisActor)
{
	if (ThisActor)
	{
		ComponentClass* ComponentClass = ThisActor->FindComponentByClass<ComponentClass>();
		if (ComponentClass == nullptr)
		{
			return FindActorComponentRecursiveOwner<ComponentClass>(ThisActor->GetOwner());
		}
	}

	return nullptr;
}

template<class ComponentClass> TArray<ComponentClass*> RevTemplateFunctions::FindAllActorComponents(const AActor *thisActor)
{
    TArray<ComponentClass*> cmpArray;
    if (thisActor)
    {
		thisActor->GetComponents<ComponentClass>(cmpArray);
    }


    return cmpArray;
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponent(const UActorComponent *ThisComponent)
{
	QUICK_SCOPE_CYCLE_COUNTER(YSTAT_FindActorComponent);
	if (!ThisComponent)
	{
		return nullptr;
	}

	AActor *ThisOwner= ThisComponent->GetOwner();
	check(ThisOwner !=NULL);
	return FindActorComponent<ComponentClass>(ThisOwner);
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponentChecked(const AActor *ThisActor)
{
	if (ThisActor)
	{
		ComponentClass* ReturnComponent = ThisActor->FindComponentByClass<ComponentClass>();
		check(ReturnComponent != nullptr);
		return ReturnComponent;
	}

	check(false);
	return nullptr;
}

template<class ComponentClass> TArray<ComponentClass*> RevTemplateFunctions::FindAllActorComponentsChecked(const AActor *thisActor)
{
	TArray<ComponentClass*> ReturnComponents;
	if (thisActor)
	{
		thisActor->GetComponents<ComponentClass>(ReturnComponents);
	}

	check(ReturnComponents.Num() > 0);
	return ReturnComponents;
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponentChecked(const UActorComponent *ThisComponent)
{
	AActor *ThisOwner = ThisComponent->GetOwner();
	check(ThisOwner != NULL);
	return FindActorComponentChecked<ComponentClass>(ThisOwner);
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponentControllerPawn(const AActor *ThisActor)
{
	if (!ThisActor)
	{
		return nullptr;
	}

	ComponentClass* ThisComponentClass = FindActorComponent<ComponentClass>(ThisActor);
	if (!ThisComponentClass)
	{
		if (const APawn* ThisPawn = Cast<APawn>(ThisActor))
		{
			return FindActorComponent<ComponentClass>(ThisPawn->Controller);
		}
		else
		if(const AController* ThisController = Cast<AController>(ThisActor))
		{
			return FindActorComponent<ComponentClass>(ThisController->GetPawn());
		}
	}

	return ThisComponentClass;
}

template<class ComponentClass> ComponentClass* RevTemplateFunctions::FindActorComponentControllerState(const AActor *ThisActor)
{
	if (!ThisActor)
	{
		return nullptr;
	}

	ComponentClass* ThisComponentClass = FindActorComponent<ComponentClass>(ThisActor);
	if (!ThisComponentClass)
	{
		if (const APawn* ThisPawn = Cast<APawn>(ThisActor))
		{
			return FindActorComponent<ComponentClass>(ThisPawn->Controller);
		}
		else
		if(const APlayerState* ThisState = Cast<APlayerState>(ThisActor))
		{
			return FindActorComponent<ComponentClass>(ThisState->GetOwner());
		}
	}

	return ThisComponentClass;
}
