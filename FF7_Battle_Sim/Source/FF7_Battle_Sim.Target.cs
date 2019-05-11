// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class FF7_Battle_SimTarget : TargetRules
{
	public FF7_Battle_SimTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "FF7_Battle_Sim" } );
	}
}
