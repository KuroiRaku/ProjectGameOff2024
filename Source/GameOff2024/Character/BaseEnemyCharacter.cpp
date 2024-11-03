// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemyCharacter.h"

#include "BaseAIController.h"
#include "Components/CapsuleComponent.h"

ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	SkeletalMesh->SetupAttachment(GetCapsuleComponent());
	SkeletalMesh->bCastDynamicShadow = false;
	SkeletalMesh->CastShadow = false;
	SkeletalMesh->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
}

void ABaseEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

