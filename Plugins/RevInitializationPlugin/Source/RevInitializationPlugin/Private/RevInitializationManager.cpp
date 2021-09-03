#include "RevInitializationManager.h"
#include "RevInitializationRetrievalInterface.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"

int32 GInitializationRequestHandle = 0;

DEFINE_LOG_CATEGORY_STATIC(LogYInitializationManager, Log, All);

IRevInitializationRetrievalInterface* GetInitializationInterface(const UObject* objCtx)
{
	UWorld* world = objCtx ? objCtx->GetWorld() : nullptr;
	if (!world)
	{
		return nullptr;
	}
	return Cast<IRevInitializationRetrievalInterface>( world->GetGameInstance());
}

URevInitializationManager* URevInitializationManager::FindInitializationManager(const UObject* objCtx)
{
	if (IRevInitializationRetrievalInterface* actorSpawnInterface = GetInitializationInterface(objCtx))
	{
		if (URevInitializationManager* initializationManager = actorSpawnInterface->GetInitializationManager())
		{
			return initializationManager;
		}
	}
	return nullptr;
}
	
void URevInitializationManager::Initialize(float refreshFrequency)
{
	m_checkInitializationStateFrequency = refreshFrequency;
	if(m_checkInitializationStateFrequency > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(
			m_initializationStateTimerHandle,
			FTimerDelegate::CreateUObject(this, &URevInitializationManager::Update),
			m_checkInitializationStateFrequency,
			true);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(m_initializationStateTimerHandle);
	}
	
}

void URevInitializationManager::Update()
{
	IRevInitializationRetrievalInterface* interface = GetInitializationInterface(this);
	if(interface == nullptr)
	{
		return;
	}
	TMap<int32, FRevInitializationContext> requestsToRemove;
	for (auto request : m_requests)
	{
		const FRevInitializationRequestEntry entry = request.Value;
		AActor* actorContext =entry.m_relevantContext;
		FRevInitializationContext initRequest = FRevInitializationContext(actorContext, entry.m_requestType, interface);
		if(initRequest.IsValid())
		{
			requestsToRemove.Add(request.Key, initRequest);	
		}
	}
	
	for (auto requestToRemove : requestsToRemove)
	{
		if(FRevInitializationRequestEntry* requestEntry = m_requests.Find(requestToRemove.Key))
		{
			requestEntry->m_delegate.ExecuteIfBound(requestToRemove.Value);
			requestEntry->m_bpDelegate.ExecuteIfBound(requestToRemove.Value);
		}
		m_requests.Remove(requestToRemove.Key);
	}
}

bool IsInitializationManagerInputValid(AActor* actorContext)
{
	return actorContext != nullptr && (actorContext->IsA<APawn>() || actorContext->IsA<APlayerController>() || actorContext->IsA<APlayerState>());
}

int32 URevInitializationManager::RequestCompleteInitializationCallback(
	AActor* actorContext,
	const FYInitializationCompleteDelegate& delegate,
	const ERevInitializationRequestSettingTypes type /* = EYInitializationRequestSettingTypes::AllComplete*/)
{
	const FString ctxStr = TEXT("UYInitializationManager::RequestCompleteInitializationCallback");

	URevInitializationManager* manager = FindInitializationManager(actorContext);
	if (manager == nullptr)
	{
		return INDEX_NONE;
	}

	if (!IsInitializationManagerInputValid(actorContext))
	{
		UE_LOG(LogYInitializationManager, Error, TEXT("%s | Invalid actor sent in [%s]"), *ctxStr, *GetNameSafe(actorContext));
		return INDEX_NONE;
	}

	FRevInitializationRequestEntry request = {};
	request.m_delegate = delegate;
	request.m_relevantContext = actorContext;
	request.m_requestType = type;

	const int32 newRequest = GInitializationRequestHandle++;
	manager->m_requests.Add(newRequest, request);

	return newRequest;
}

int32 URevInitializationManager::RequestCompleteInitializationCallbackBlueprint(
	AActor* actorContext,
	FYInitializationCompleteDelegateDynamic delegate,
	bool& outSuccess,
	ERevInitializationRequestSettingTypes type)
{
	URevInitializationManager* manager = FindInitializationManager(actorContext);
	if(!manager)
	{
		outSuccess = false;
		return INDEX_NONE;
	}

	if(!IsInitializationManagerInputValid(actorContext))
	{
		outSuccess = false;
		UE_LOG(LogYInitializationManager, Error, TEXT("UYInitializationManager::RequestCompleteInitializationCallback | Invalid actor sent in [%s]"), *GetNameSafe(actorContext));
		return INDEX_NONE;
	}

	outSuccess = true;
	FRevInitializationRequestEntry request = {};
	request.m_bpDelegate = delegate;
	request.m_relevantContext = actorContext;
	request.m_requestType = type;
	const int32 newRequest = GInitializationRequestHandle++;
	manager->m_requests.Add(newRequest, request);
	return newRequest;
	
}

FString URevInitializationManager::GetDebugState(const UObject* objCtx)
{
	FString returnEntry = {};
	URevInitializationManager* manager = FindInitializationManager(objCtx);
	if(!manager)
	{
		return returnEntry;
	}
	
	IRevInitializationRetrievalInterface* interface = GetInitializationInterface(objCtx);
	if(interface == nullptr)
	{
		return returnEntry;
	}
	returnEntry = FString::Printf(TEXT(" Amount pending requests: %i "), manager->m_requests.Num());
	int32 requestCounter = 0;
	for (auto request  : manager->m_requests)
	{
		const FRevInitializationRequestEntry entry = request.Value;
		AActor* actorContext =entry.m_relevantContext;
		FRevInitializationContext initRequest = FRevInitializationContext(actorContext, entry.m_requestType, interface);
		returnEntry += FString::Printf(TEXT("%s, "), *initRequest.ToString());
		requestCounter++;
	}
	return returnEntry;
}
