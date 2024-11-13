// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CameraController.generated.h"

class UBehaviorTree;
struct FInputActionValue;
struct FInputActionInstance;
class UInputAction;
class UInputMappingContext;

UCLASS()
class GAMEOFF2024_API ACameraController : public APlayerController
{
	GENERATED_BODY()

public:

	ACameraController();

	UFUNCTION(BlueprintCallable)
	FHitResult Hit();
	void SelectCharacter(const FInputActionValue& Value);
	void Move(const FInputActionValue& Instance);
	void AttachCamera();

	virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta = (AllowPrivateAccess="true"))
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta = (AllowPrivateAccess="true"))
	UInputAction* LeftClickAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta = (AllowPrivateAccess="true"))
	UInputAction* RightClickAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Input", meta = (AllowPrivateAccess="true"))
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Input", meta = (AllowPrivateAccess="true"))
	UInputAction* AttachCameraAction;

	UPROPERTY(BlueprintReadWrite)
	ACharacter* SelectedCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeCharacterWasSelected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Speed = 300;
	UPROPERTY(BlueprintReadWrite)
	bool Attached;
};
