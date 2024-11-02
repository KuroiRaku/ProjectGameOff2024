// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameOff2024 : ModuleRules
{
	public GameOff2024(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] { "GameOff2024" });
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
			"EnhancedInput", "AIModule" });
	}
}
