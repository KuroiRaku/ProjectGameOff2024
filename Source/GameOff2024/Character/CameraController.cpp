// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameTime.h"

ACameraController::ACameraController()
	: TimeCharacterWasSelected(0.0f)
{
	InputComponent = CreateDefaultSubobject<UEnhancedInputComponent>("InputComponent");
}

FHitResult ACameraController::Hit()
{
	FVector2D MouseLocation;
	GetMousePosition(MouseLocation.X, MouseLocation.Y);
	FVector WorldMouseLocation;
	FVector WorldMouseDirection;
	UGameplayStatics::DeprojectScreenToWorld(this, MouseLocation, WorldMouseLocation, WorldMouseDirection);
	FHitResult Out{};
	GetWorld()->LineTraceSingleByChannel(Out, WorldMouseLocation, WorldMouseDirection + WorldMouseDirection * 100000, ECC_GameTraceChannel1);
	return Out;
}

void ACameraController::SelectCharacter_Implementation(const FInputActionValue& Value) {
	auto HitActor = Hit().GetActor();
	
	if(auto* TentativeSelection = Cast<ACharacter>(HitActor); IsValid(TentativeSelection))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Selected character %s"), *TentativeSelection->GetName()));
		SelectedCharacter = TentativeSelection;
		TimeCharacterWasSelected = (float)GetWorld()->GetTimeSeconds();
	}
}


void ACameraController::Move(const FInputActionValue& Value) {
	if(!Attached)
		GetPawn()->GetMovementComponent()->AddInputVector(Value.Get<FVector>() * Speed);	
}

void ACameraController::AttachCamera()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Attach"));
}

void ACameraController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (auto* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(LeftClickAction, ETriggerEvent::Triggered, this, &ACameraController::SelectCharacter);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACameraController::Move);
		EnhancedInput->BindAction(AttachCameraAction, ETriggerEvent::Triggered, this, &ACameraController::AttachCamera);
	}
}

void ACameraController::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
	EnableInput(this);
	/*SetShowMouseCursor(true);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping, 1000000);
	}*/

}
