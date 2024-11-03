// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BaseEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEOFF2024_API ABaseEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABaseEnemyCharacter();

	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;
};
