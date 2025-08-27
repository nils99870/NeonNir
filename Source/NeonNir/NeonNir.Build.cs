// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NeonNir : ModuleRules
{
	public NeonNir(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NeonNir",
			"NeonNir/Variant_Platforming",
			"NeonNir/Variant_Platforming/Animation",
			"NeonNir/Variant_Combat",
			"NeonNir/Variant_Combat/AI",
			"NeonNir/Variant_Combat/Animation",
			"NeonNir/Variant_Combat/Gameplay",
			"NeonNir/Variant_Combat/Interfaces",
			"NeonNir/Variant_Combat/UI",
			"NeonNir/Variant_SideScrolling",
			"NeonNir/Variant_SideScrolling/AI",
			"NeonNir/Variant_SideScrolling/Gameplay",
			"NeonNir/Variant_SideScrolling/Interfaces",
			"NeonNir/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
