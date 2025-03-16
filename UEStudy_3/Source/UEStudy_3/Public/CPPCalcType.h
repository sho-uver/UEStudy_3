// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCalcType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECPPCalcType : uint8
{
	Add,
	Subtract,
	Multiply,
	Divide
};
