// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5Playground : ModuleRules
{
	public UE5Playground(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"RevUnrealBasics", 
			"GameplayAbilities", 
			"GameplayTasks",
			"GameplayTags",
			"RevInitializationPlugin"
		});

	}
}
