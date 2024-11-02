// Copyright Epic Games, Inc. All Rights Reserved.


#include "TP_WeaponComponent.h"
#include "Character/GameOff2024Character.h"
#include "Magic/GameOff2024Projectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UTP_WeaponComponent::UTP_WeaponComponent()
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}


void UTP_WeaponComponent::Fire()
{
	if (!IsValid(Character) || !IsValid(Character->GetController()))
	{
		return;
	}

	// Try and fire a projectile
	if (IsValid(ProjectileClass))
	{
		if (UWorld* const World = GetWorld(); IsValid(World))
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
	
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
			// Spawn the projectile at the muzzle
			World->SpawnActor<AGameOff2024Projectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
	
	// Try and play the sound if specified
	if (IsValid(FireSound))
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	}
	
	// Try and play a firing animation if specified
	if (IsValid(FireAnimation))
	{
		// Get the animation object for the arms mesh
		if (UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance(); IsValid(AnimInstance))
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

bool UTP_WeaponComponent::AttachWeapon(AGameOff2024Character* TargetCharacter)
{
	Character = TargetCharacter;

	// Check that the character is valid, and has no weapon component yet
	if (!IsValid(Character) || Character->GetInstanceComponents().FindItemByClass<UTP_WeaponComponent>())
	{
		return false;
	}

	// Attach the weapon to the First Person Character
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

	// add the weapon as an instance component to the character
	Character->AddInstanceComponent(this);

	// Set up action bindings
	const APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()); 
	if (IsValid(PlayerController))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (IsValid(Subsystem))
		{
			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
		if (IsValid(EnhancedInputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UTP_WeaponComponent::Fire);
		}
	}

	return true;
}

void UTP_WeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsValid(Character))
	{
		return;
	}

	APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
	if (IsValid(PlayerController))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (IsValid(Subsystem))
		{
			Subsystem->RemoveMappingContext(FireMappingContext);
		}
	}
}