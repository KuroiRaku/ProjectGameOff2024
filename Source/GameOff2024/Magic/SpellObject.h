// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicInfo.h"
#include "GameFramework/Actor.h"
#include "SpellObject.generated.h"

// Spawn this object
UCLASS()
class GAMEOFF2024_API ASpellObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpellObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FMagicInfo MagicInfo;
};
