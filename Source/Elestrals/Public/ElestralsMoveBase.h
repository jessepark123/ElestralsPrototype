// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Elements.h"
#include "ElestralsMoveBase.generated.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class ESkillTypes : uint8
{
	Light UMETA(DisplayName = "Light"),
	Heavy UMETA(DisplayName = "Heavy"),
	Ultimate UMETA(DisplayName = "Ultimate")
};


USTRUCT(BlueprintType)
struct FMoveAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		FString MoveName = "Test Move Name";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		float MoveDamage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		int LevelToAcquireMoveAt = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		FVector HitboxSize = FVector(200.0f, 200.0f, 100.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		float EnemyLaunchMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		float EnemyLaunchZOffset = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		EElements MoveType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		UAnimMontage* AnimationToPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		float AnimationPlaybackSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move Attributes")
		USoundBase* MoveSound;

	/*The type of skill this move is*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Tree Setup")
		ESkillTypes skillType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Tree Setup")
		FString MoveDescription = "Description Goes Here";
	

};
UCLASS(Blueprintable)
class ELESTRALS_API UElestralsMoveBase : public UObject
{
	GENERATED_BODY()
		
public:


		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FMoveAttributes moveAttributes;

		UFUNCTION(BlueprintCallable)
		FMoveAttributes GetMoveAttributes();

		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void CustomMoveFunctionality(ACH_ElestralBase* ElestralToApplyLogicTo);

	
};
