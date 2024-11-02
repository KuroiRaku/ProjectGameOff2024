// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


// This is the loadout
// When we open loadup screen, they should be able to get every information in this class
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEOFF2024_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
};
