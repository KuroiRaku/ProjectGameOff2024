// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Character/StatsComponent.h"
#include "EquipmentItem.generated.h"

UENUM(BlueprintType)
enum class EEquipmentUsageType : uint8
{
	ArmorSuit UMETA(DisplayName = "ArmorSuit"),
	LeftHandedEquipment UMETA(DisplayName = "LeftHandedEquipment"),
	RightHandedEquipment UMETA(DisplayName = "RightHandedEquipment"),
	OneHandedEquipment UMETA(DisplayName = "OneHandedEquipment"),
	TwoHandedEquipment UMETA(DisplayName = "TwoHandedEquipment")
};

/**
 *
 */
UCLASS()
class GAMEOFF2024_API AEquipmentItem : public AItem
{
	GENERATED_BODY()
public:

	// Set default value
	AEquipmentItem();

	UFUNCTION(BlueprintCallable)
	FString GetName() { return Name; }

	UFUNCTION(BlueprintCallable)
	FText GetDescription() { return Description; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	// Adjust the stats when equipping the equipment
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStatsComponent* StatsAdjustment;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EEquipmentUsageType EquipmentUsageType;
};
