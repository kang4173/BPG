// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BPG : ModuleRules
{
	public BPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
