// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentItem.h"

AEquipmentItem::AEquipmentItem()
{
	StatsAdjustment = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
}