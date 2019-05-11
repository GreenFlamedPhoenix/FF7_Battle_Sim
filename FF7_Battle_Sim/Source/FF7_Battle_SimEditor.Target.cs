// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class FF7_Battle_SimEditorTarget : TargetRules
{
	public FF7_Battle_SimEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "FF7_Battle_Sim" } );
	}
}
