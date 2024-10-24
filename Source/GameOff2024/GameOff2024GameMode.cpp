// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameOff2024GameMode.h"
#include "GameOff2024Character.h"
#include "UObject/ConstructorHelpers.h"

AGameOff2024GameMode::AGameOff2024GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
