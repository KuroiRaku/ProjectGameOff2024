#pragma once

#include "MagicEnums.generated.h"

UENUM(BlueprintType)
enum class EMagicElement : uint8
{
	Water UMETA(DisplayName = "Water"),
	Fire UMETA(DisplayName = "Fire"),
	Electric UMETA(DisplayName = "Electric"),
	Earth UMETA(DisplayName = "Earth")
};

UENUM(BlueprintType)
enum class EMagicShape : uint8
{
	Arrow UMETA(DisplayName = "Arrow"),
	Sphere UMETA(DisplayName = "Sphere"),
	Cube UMETA(DisplayName = "Cube"),
	Wall UMETA(DisplayName = "Wall")
};

UENUM(BlueprintType)
enum class EMagicSpeed : uint8
{
	Fast UMETA(DisplayName = "Fast"),
	Standard UMETA(DisplayName = "Standart"),
	Slow UMETA(DisplayName = "Slow")
};

UENUM(BlueprintType)
enum class EMagicSize : uint8
{
	Small UMETA(DisplayName = "Small"),
	Medium UMETA(DisplayName = "Medium"),
	Big UMETA(DisplayName = "Big")
};