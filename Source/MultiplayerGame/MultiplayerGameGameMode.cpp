// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerGameGameMode.h"
#include "MultiplayerGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerGameGameMode::AMultiplayerGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
