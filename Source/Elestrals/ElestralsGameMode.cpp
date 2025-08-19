// Copyright Epic Games, Inc. All Rights Reserved.

#include "ElestralsGameMode.h"
#include "ElestralsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AElestralsGameMode::AElestralsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/CentralClasses/BP_C_ElestralsPlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
