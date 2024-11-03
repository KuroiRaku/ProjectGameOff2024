// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyCharacter.h"

#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"

ABaseEnemyCharacter::ABaseEnemyCharacter()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
	Controller = CreateDefaultSubobject<AAIController>("AIController");

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	SkeletalMesh->SetupAttachment(GetCapsuleComponent());
	SkeletalMesh->bCastDynamicShadow = false;
	SkeletalMesh->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	SkeletalMesh->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
}

void ABaseEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
