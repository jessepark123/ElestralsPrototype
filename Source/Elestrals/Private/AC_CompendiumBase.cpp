// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_CompendiumBase.h"

// Sets default values for this component's properties
UAC_CompendiumBase::UAC_CompendiumBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UAC_CompendiumBase::BeginPlay()
{
	Super::BeginPlay();
	PopulateCompendium();
	// ...
	
}


// Called every frame
void UAC_CompendiumBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_CompendiumBase::PopulateCompendium()
{
	TotalElestralClassList.Empty();
	GetDerivedClasses(ACH_ElestralBase::StaticClass(), TotalElestralClassList, true);
	/*for (TObjectIterator<UClass> Elestral; Elestral; ++Elestral)
	{
		if (Elestral->IsChildOf(ACH_ElestralBase::StaticClass()) && !Elestral->HasAnyClassFlags(CLASS_Abstract))
		{
			if (!TotalElestralClassList.Contains(*Elestral))
			{
				TotalElestralClassList.AddUnique(*Elestral); 
			}
		}
	}*/
}

