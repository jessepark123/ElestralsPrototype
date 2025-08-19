// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ELESTRALS_API Elements
{
public:
	Elements();
	~Elements();
};

UENUM(BlueprintType)
enum class EElements : uint8
{
	Earth UMETA(DisplayName = "Earth"),
	Wind UMETA(DisplayName = "Wind"),
	Water UMETA(DisplayName = "Water"),
	Fire UMETA(DisplayName = "Fire"),
	Frost UMETA(DisplayName = "Frost"),
	Thunder UMETA(DisplayName = "Thunder"),
	Solar UMETA(DisplayName = "Solar"),
	Lunar UMETA(DisplayName = "Lunar")
};