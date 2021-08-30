#include "RevInitializationTypes.h"
#include "RevInitializationRetrievalInterface.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"

bool IsValidController(ENetRole baseRole, AController* controller)
{
	if(baseRole == ROLE_SimulatedProxy)
	{
		return true;
	}
	if(controller != nullptr)
	{
		return controller->GetPawn() != nullptr && controller->PlayerState != nullptr;
	}
	return false;
}

bool IsValidPlayerState(APlayerState* state)
{
	if(state)
	{
		if(state->GetUniqueId().IsValid())
		{
			return true;
		}
	}
	return false;
}

bool IsValidPawn(APawn* pawn)
{
	if(pawn != nullptr && pawn->GetPlayerState() != nullptr)
	{
		if(pawn->GetLocalRole() == ROLE_SimulatedProxy)
		{
			return true;
		}
		else
		{
			if(pawn->GetController() && pawn->GetController()->GetPawn())
			{
				return true;
			}
		}
	}
	return false;
}

FRevInitializationContext::FRevInitializationContext(AActor* actorContext, ERevInitializationRequestSettingTypes type,IRevInitializationRetrievalInterface* initInterface)
{
	m_requestSettingType = type;
	m_playerState = nullptr;
	if(APawn* character = Cast<APawn>(actorContext))
	{
		m_pawn = character;
		m_controller = Cast<APlayerController>(character->GetController());
		m_playerState = character->GetPlayerState();
	}
	else if(APlayerController* controller = Cast<APlayerController>(actorContext))
	{
		m_pawn = controller && controller->GetPawn() ? controller->GetPawn() : nullptr;
		m_controller = controller;
		m_playerState = controller->GetPlayerState<APlayerState>();
	}
	else if(APlayerState* state = Cast<APlayerState>(actorContext))
	{
		m_pawn = state->GetPawn();
		m_controller = m_pawn ? Cast<APlayerController>(m_pawn->GetController()) : nullptr;
		m_playerState = state;
	}
	m_userId = m_playerState != nullptr && m_playerState->GetUniqueId().IsValid() ? m_playerState->GetUniqueId().ToString() : TEXT("");
	if(initInterface)
	{
		m_isAdditionalIntialized = initInterface->IsAdditionalInitializationComplete(*this, m_requestSettingType);
	}
	else
	{
		m_isAdditionalIntialized = true;
	}
}

 FString FRevInitializationContext::ToString() const
 {
	FString baseString = FString::Printf(TEXT("IsValid [%i], m_controller [%s], m_playerState [%s],  m_pawn[%s], m_userId[%s], m_isAdditionalIntialized[%i], m_requestSettingType[%i]"),
		(int32)IsValid(),
		*GetNameSafe(m_controller),
		*GetNameSafe(m_playerState),
		*GetNameSafe(m_pawn),
		*m_userId,
		(int32)m_isAdditionalIntialized,
		(int32)m_requestSettingType
		);
 	return baseString;
 }

bool FRevInitializationContext::IsValid() const
{
	return m_isAdditionalIntialized && IsValidPawn(m_pawn) && IsValidController(m_pawn->GetLocalRole(), m_controller) && IsValidPlayerState(m_playerState) && !m_userId.IsEmpty();
}