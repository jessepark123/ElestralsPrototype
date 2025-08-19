// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ElestralsItem.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	ElestralsEquipItem UMETA(DisplayName = "ElestralsEquipItem"),
	Consumable UMETA(DisplayName = "Consumable"),
	PlayerEquipItem UMETA(DisplayName = "PlayerEquipItem"),
};
/**
 * 
 */
UCLASS()
class ELESTRALS_API UElestralsItem : public UObject
{
	GENERATED_BODY()
	

public:
	/*The type of item this item is*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType;
};
