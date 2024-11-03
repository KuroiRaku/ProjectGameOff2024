// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

class UBehaviorTree;
class UAIPerceptionComponent;
class UBlackboardComponent;

UCLASS()
class GAMEOFF2024_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseAIController();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	UBlackboardComponent* BlackboardComponent;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviorTree;
};
