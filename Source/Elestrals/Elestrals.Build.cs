// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Elestrals : ModuleRules
{
	public Elestrals(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
