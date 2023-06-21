// Copyright Epic Games, Inc. All Rights Reserved.

#include "BPGGameMode.h"
#include "BPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABPGGameMode::ABPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
