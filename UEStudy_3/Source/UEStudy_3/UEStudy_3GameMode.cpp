// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEStudy_3GameMode.h"
#include "UEStudy_3Character.h"
#include "UObject/ConstructorHelpers.h"

AUEStudy_3GameMode::AUEStudy_3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
