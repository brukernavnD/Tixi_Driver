// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tixi_Driver : ModuleRules
{
	public Tixi_Driver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
