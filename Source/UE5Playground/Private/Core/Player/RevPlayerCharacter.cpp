// Copyright Epic Games, Inc. All Rights Reserved.
#include "Core/Player/RevPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Core/RevCommonFunctions.h"
#include "Core/Player/RevPlayerTypes.h"
#include "Game/GAAS/RevAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ARevPlayerCharacter

ARevPlayerCharacter::ARevPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	AbilityComponent = CreateDefaultSubobject<UYRevAbilitySystemComponent>(TEXT("RevSystemAbilityComponent"));
}

void ARevPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if(URevPlayerInitializationDA* daAsset = URevCommonFunctions::FindPlayerInitializationDataAsset(this))
	{
		check(daAsset->m_meshToUse);
		check(daAsset->m_animInstanceClass);
		GetMesh()->SetSkeletalMeshWithoutResettingAnimation(daAsset->m_meshToUse);
		GetMesh()->SetAnimInstanceClass(daAsset->m_animInstanceClass);
	}	
}

void ARevPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ARevPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARevPlayerCharacter::MoveRight);

}

void ARevPlayerCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		FVector loc;
		FRotator rot;
		Controller->GetPlayerViewPoint(loc, rot);
		const FVector Direction = FRotationMatrix(rot).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARevPlayerCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		FVector loc;
        FRotator rot;
        Controller->GetPlayerViewPoint(loc, rot);
		const FVector Direction = FRotationMatrix(rot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}
