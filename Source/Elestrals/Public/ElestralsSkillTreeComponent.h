// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElestralsMoveBase.h"
#include "ElestralsSkillTreeComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELESTRALS_API UElestralsSkillTreeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UElestralsSkillTreeComponent();

	/*The total moves available to the Elestral's skill tree */
	UPROPERTY(BlueprintReadWrite, Category = "Skill Tree Setup")
	TArray<UElestralsMoveBase*> TotalMovesInSkillTree;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*Returns ALL skills in the Elestral Skill Tree*/
	UFUNCTION(BlueprintCallable)
	TArray<UElestralsMoveBase*> GetSkillTreeMoves();

	/*Returns all LIGHT skills in the Elestral Skill Tree*/
	UFUNCTION(BlueprintCallable)
	TArray<UElestralsMoveBase*> GetLightSkillTreeMoves();

	/*Returns all HEAVY skills in the Elestral Skill Tree*/
	UFUNCTION(BlueprintCallable)
	TArray<UElestralsMoveBase*> GetHeavySkillTreeMoves();

	/*Returns all ULTIMATE skills in the Elestral Skill Tree*/
	UFUNCTION(BlueprintCallable)
	TArray<UElestralsMoveBase*> GetUltimateSkillTreeMoves();
};
