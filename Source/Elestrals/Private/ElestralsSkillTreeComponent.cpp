// Fill out your copyright notice in the Description page of Project Settings.


#include "ElestralsSkillTreeComponent.h"

// Sets default values for this component's properties
UElestralsSkillTreeComponent::UElestralsSkillTreeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UElestralsSkillTreeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UElestralsSkillTreeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<UElestralsMoveBase*> UElestralsSkillTreeComponent::GetSkillTreeMoves()
{
	return TotalMovesInSkillTree;
}

TArray<UElestralsMoveBase*> UElestralsSkillTreeComponent::GetLightSkillTreeMoves()
{
	TArray<UElestralsMoveBase*> lightSkillsInSkillTree;

	for (UElestralsMoveBase* currentMove : TotalMovesInSkillTree)
	{
		ESkillTypes skillType = currentMove->GetMoveAttributes().skillType;
		if (skillType == ESkillTypes::Light)
		{
			lightSkillsInSkillTree.Add(currentMove);
		}
	} 
	return lightSkillsInSkillTree;
}

TArray<UElestralsMoveBase*> UElestralsSkillTreeComponent::GetHeavySkillTreeMoves()
{
	TArray<UElestralsMoveBase*> heavySkillsInSkillTree;

	for (UElestralsMoveBase* currentMove : TotalMovesInSkillTree)
	{
		ESkillTypes skillType = currentMove->GetMoveAttributes().skillType;
		if (skillType == ESkillTypes::Heavy)
		{
			heavySkillsInSkillTree.Add(currentMove);
		}
	}
	return heavySkillsInSkillTree;
}

TArray<UElestralsMoveBase*> UElestralsSkillTreeComponent::GetUltimateSkillTreeMoves()
{
	TArray<UElestralsMoveBase*> ultimateSkillsInSkillTree;

	for (UElestralsMoveBase* currentMove : TotalMovesInSkillTree)
	{
		ESkillTypes skillType = currentMove->GetMoveAttributes().skillType;
		if (skillType == ESkillTypes::Ultimate)
		{
			ultimateSkillsInSkillTree.Add(currentMove);
		}
	}
	return ultimateSkillsInSkillTree;
}

