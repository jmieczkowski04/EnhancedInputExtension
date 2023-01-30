// Copyright 2023 (C) Jakub Mieczkowski. All rights reserved.


using UnrealBuildTool;

public class EnhancedInputExtension : ModuleRules
{
	public EnhancedInputExtension(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "EnhancedInput" });
	}
}
