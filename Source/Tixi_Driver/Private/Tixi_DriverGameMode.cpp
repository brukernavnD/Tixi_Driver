// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tixi_Driver/Public/Tixi_DriverGameMode.h"

#include "UObject/ConstructorHelpers.h"

ATixi_DriverGameMode::ATixi_DriverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
