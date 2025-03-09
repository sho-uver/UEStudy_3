// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEStudy_3 : ModuleRules
{
	public UEStudy_3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
