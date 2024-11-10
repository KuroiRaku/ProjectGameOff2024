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

USTRUCT(BlueprintType)
struct FSpellElementPropertyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSpellElementPropertyData()
		: Damage(10.0f)
		, Speed(100.0f)
		, ManaCost(5.0f)
		, ChargingUpTime(0.0f)
		, Accuracy(10.0f)
		, TimeBeforeDissipating(5.0f)
		, Hitpoint(20.0f)
		, CooldownTime(1.0f)
	{}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicElement ElementType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ManaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargingUpTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeDissipating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hitpoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;
};

USTRUCT(BlueprintType)
struct FSpellShapePropertyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSpellShapePropertyData()
		: Damage(10.0f)
		, Speed(100.0f)
		, ManaCost(1.0f)
		, ChargingUpTime(0.0f)
		, Accuracy(10.0f)
		, TimeBeforeDissipating(5.0f)
		, Hitpoint (0.0f)
	{}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicShape ShapeType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ManaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargingUpTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeDissipating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hitpoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;
};

USTRUCT(BlueprintType)
struct FSpellSizePropertyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSpellSizePropertyData()
		: Damage(10.0f)
		, Speed(100.0f)
		, ManaCost(1.0f)
		, ChargingUpTime(0.0f)
		, Accuracy(10.0f)
		, TimeBeforeDissipating(5.0f)
	{}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicSize SizeType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ManaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargingUpTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeDissipating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hitpoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleMultiplier;
};

USTRUCT(BlueprintType)
struct FSpellSpeedPropertyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSpellSpeedPropertyData()
		: Damage(10.0f)
		, Speed(100.0f)
		, ManaCost(1.0f)
		, ChargingUpTime(0.0f)
		, Accuracy(10.0f)
		, TimeBeforeDissipating(5.0f)
	{}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EMagicSpeed SpeedType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ManaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargingUpTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeDissipating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hitpoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;
};


USTRUCT(BlueprintType)
struct FSpellPropertyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSpellPropertyData()
		: Damage(10.0f)
		, Speed(100.0f)
		, ManaCost(1.0f)
		, ChargingUpTime(0.0f)
		, Accuracy(10.0f)
		, TimeBeforeDissipating(5.0f)
	{
		MagicInfo.Element = EMagicElement::Fire;
		MagicInfo.Shape = EMagicShape::Wall;
		MagicInfo.Size = EMagicSize::Medium;
		MagicInfo.Speed = EMagicSpeed::Standard;
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FMagicInfo MagicInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ManaCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ChargingUpTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeDissipating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hitpoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleMultiplier;
};