// Copyright Druid Mechanics

using UnrealBuildTool;
using System.Collections.Generic;

public class FPSEditorTarget : TargetRules
{
	public FPSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;

		ExtraModuleNames.AddRange( new string[] { "FPS" } );
	}
}
