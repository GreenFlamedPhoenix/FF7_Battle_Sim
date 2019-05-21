// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "CurrentMapTheme.generated.h"

/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class CurrentMapTheme : uint8
{
	MidgarStreetsTheme 		UMETA(DisplayName = "MidgarStreetsTheme"),
	ForestTheme			 	UMETA(DisplayName = "ForestTheme")
};
