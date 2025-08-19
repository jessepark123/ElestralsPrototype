// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_ElestralsData.h"

// Sets default values for this component's properties
UAC_ElestralsData::UAC_ElestralsData()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_ElestralsData::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

TArray<UElestralsMoveBase*> UAC_ElestralsData::GetElestralCurrentActiveLightCombo()
{
	return ElestralStats.CurrentActiveLightCombo;
}

UElestralsMoveBase* UAC_ElestralsData::GetElestralCurrentHeavyAttack()
{
	return ElestralStats.CurrentActiveHeavyAttack;
}

UElestralsMoveBase* UAC_ElestralsData::GetElestralCurrentUltimateAttack()
{
	return ElestralStats.CurrentActiveUltimateAttack;
}

FString UAC_ElestralsData::GetElestralName()
{
	return ElestralStats.ElestralName;
}

EElements UAC_ElestralsData::GetElestralElement()
{
	return ElestralStats.ElestralElement;
}

float UAC_ElestralsData::GetElestralHealth()
{
	return ElestralStats.ElestralHealth;
}

float UAC_ElestralsData::GetElestralCurrentHealth()
{
	return ElestralStats.ElestralCurrentHealth;
}

float UAC_ElestralsData::GetElestralSpeed()
{
	return ElestralStats.ElestralSpeed;
}

float UAC_ElestralsData::GetElestralAttack()
{
	return ElestralStats.ElestralAttack;
}

float UAC_ElestralsData::GetElestralDefense()
{
	return ElestralStats.ElestralDefense;
}

FElestralStats UAC_ElestralsData::GetElestralStats()
{
	return ElestralStats;
}

UTexture2D* UAC_ElestralsData::GetElestralDisplayImage()
{
	return ElestralStats.ElestralDisplayImage;
}

TSubclassOf<ACH_ElestralBase> UAC_ElestralsData::GetElestralClass()
{
	return ElestralStats.ElestralClass;
}

TArray<UElestralsMoveBase*> UAC_ElestralsData::SetElestralCurrentActiveLightCombo(TArray<UElestralsMoveBase*> inLightCombo)
{
	ElestralStats.CurrentActiveLightCombo = inLightCombo;
	return ElestralStats.CurrentActiveLightCombo;
}

UElestralsMoveBase* UAC_ElestralsData::SetElestralCurrentHeavyAttack(UElestralsMoveBase* inHeavyAttack)
{
	ElestralStats.CurrentActiveHeavyAttack = inHeavyAttack;
	return ElestralStats.CurrentActiveHeavyAttack;
}

UElestralsMoveBase* UAC_ElestralsData::SetElestralCurrentUltimateAttack(UElestralsMoveBase* inUltimateAttack)
{
	ElestralStats.CurrentActiveUltimateAttack = inUltimateAttack;
	return ElestralStats.CurrentActiveUltimateAttack;
}

FString UAC_ElestralsData::SetElestralName(FString inName)
{
	ElestralStats.ElestralName = inName;
	return ElestralStats.ElestralName;
}

EElements UAC_ElestralsData::SetElestralElement(EElements inElement)
{
	ElestralStats.ElestralElement = inElement;
	return ElestralStats.ElestralElement;
}

float UAC_ElestralsData::SetElestralHealth(float inHealth)
{
	ElestralStats.ElestralHealth = inHealth;
	return ElestralStats.ElestralHealth;
}

float UAC_ElestralsData::SetElestralCurrentHealth(float inCurrentHealth)
{
	ElestralStats.ElestralCurrentHealth = inCurrentHealth;

	return ElestralStats.ElestralCurrentHealth;
}

float UAC_ElestralsData::SetElestralSpeed(float inSpeed)
{
	ElestralStats.ElestralSpeed = inSpeed;
	return ElestralStats.ElestralSpeed;
}

float UAC_ElestralsData::SetElestralAttack(float inATK)
{
	ElestralStats.ElestralAttack = inATK;
	return ElestralStats.ElestralAttack;
}

float UAC_ElestralsData::SetElestralDefense(float inDEF)
{
	ElestralStats.ElestralDefense = inDEF;
	return ElestralStats.ElestralDefense;
}

FElestralStats UAC_ElestralsData::SetElestralStats(FElestralStats inStats)
{
	ElestralStats = inStats;
	return ElestralStats;
}

UTexture2D* UAC_ElestralsData::SetElestralDisplayImage(UTexture2D* TextureToSet)
{
	ElestralStats.ElestralDisplayImage = TextureToSet;
	return ElestralStats.ElestralDisplayImage;
}

TSubclassOf<ACH_ElestralBase> UAC_ElestralsData::SetElestralClass(TSubclassOf<ACH_ElestralBase> inClass)
{
	ElestralStats.ElestralClass = inClass;
	return ElestralStats.ElestralClass;
}

bool UAC_ElestralsData::AddExperienceToElestral(int ExperienceToAdd)
{
	ElestralStats.ElestralCurrentXP += ExperienceToAdd;
	this->CalculateElestralStats();

	if (ElestralStats.ElestralTotalXPToNextLevel <= 0)
	{
		ElestralStats.ElestralLevel++;
		ElestralStats.ElestralCurrentXP = 0 - ElestralStats.ElestralTotalXPToNextLevel;
		this->CalculateElestralStats();
		return true;
	}
	return false;
}

void UAC_ElestralsData::CalculateElestralStats()
{
	float tempLevel = ElestralStats.ElestralLevel;

	ElestralStats.ElestralHealth = ((ElestralBaseStats.ElestralBaseHealth * (ElestralStats.ElestralLevel / 4)) + 5);
	ElestralStats.ElestralAttack = ((ElestralBaseStats.ElestralBaseAttack * (ElestralStats.ElestralLevel / 5)) + 1);
	ElestralStats.ElestralDefense = ((ElestralBaseStats.ElestralBaseDefense * (ElestralStats.ElestralLevel / 5)) + 1);
	ElestralStats.ElestralSpeed = ((ElestralBaseStats.ElestralBaseSpeed * (FMath::Clamp((tempLevel/10), 1.0f, 100.0f))));
	ElestralStats.ElestralTotalXPToNextLevel = ((ElestralStats.ElestralLevel * 3) * (1 / ElestralStats.ElestralXPGrowthModifier)) - ElestralStats.ElestralCurrentXP;
	ElestralStats.ElestralCurrentHealth = ElestralStats.ElestralHealth;
}




// Called every frame
void UAC_ElestralsData::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

