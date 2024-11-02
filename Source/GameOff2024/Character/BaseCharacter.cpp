// Copyright Epic Games, Inc. All Rights Reserved.

#include "BaseCharacter.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Engine/LocalPlayer.h"
#include "StatsComponent.h"
#include "Items/InventoryComponent.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABaseCharacter

ABaseCharacter::ABaseCharacter()
	: Name ("Default")
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(50.f, 96.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));

	StatsComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
}