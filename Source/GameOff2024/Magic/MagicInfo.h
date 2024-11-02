// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MagicEnums.h"
#include "MagicInfo.generated.h"

USTRUCT(BlueprintType)
struct FMagicInfo
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicElement Element;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicShape Shape;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicSize Size;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicSpeed Speed;
};
