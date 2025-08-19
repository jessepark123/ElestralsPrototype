// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_ElestralsTeamComponent.h"

// Sets default values for this component's properties
UAC_ElestralsTeamComponent::UAC_ElestralsTeamComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bTickEvenWhenPaused = true;
	// ...
}


// Called when the game starts
void UAC_ElestralsTeamComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_ElestralsTeamComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FElestralStats UAC_ElestralsTeamComponent::AddElestralStatsToTeam(FElestralStats StatsToAdd)
{
	TeamStatList.Add(StatsToAdd);
	return StatsToAdd;
}

ACH_ElestralBase* UAC_ElestralsTeamComponent::CreateFollowingElestral()
{
	if (TeamStatList.IsValidIndex(0)) 
	{
		FElestralStats tempStats = TeamStatList[0];

		FVector SpawnLoc(GetOwner()->GetActorLocation());

		FRotator SpawnRot(GetOwner()->GetActorRotation());

		FActorSpawnParameters SpawnInfo;

		CurrentFollowingElestral = Cast<ACH_ElestralBase>(GetWorld()->SpawnActor(tempStats.ElestralClass, &SpawnLoc, &SpawnRot, SpawnInfo));

		//CurrentFollowingElestral = GetWorld()->SpawnActorDeferred(tempStats.ElestralClass, FTransform(SpawnRot, SpawnLoc, FVector(1, 1 , 1)), this->GetOwner());

		//CurrentFollowingElestral->SetElestralOwner(Cast<ACharacter>(this->GetOwner())); //don't put a teamcomponent on any actor that is not an ACharacter ** IMPORTANT

	    //	CurrentFollowingElestral->FinishSpawning();

		CurrentFollowingElestral->Initialize(Cast<ACharacter>(this->GetOwner()));

		CurrentFollowingElestral->SetupElestralData(TeamStatList[0]);

		CurrentFollowingElestral->RefreshStructDataImplementation();

		return CurrentFollowingElestral;
	}
	return nullptr;
}

void UAC_ElestralsTeamComponent::DestroyFollowingElestral()
{
	CurrentFollowingElestral->Destroy();
}

void UAC_ElestralsTeamComponent::SwapElestralTeamPositions(int32 ElestralToMove, int32 SlotToMoveTo)
{
	if (ElestralToMove != SlotToMoveTo) {
		if (TeamStatList.IsValidIndex(SlotToMoveTo)) {
			if (CurrentFollowingElestral) {
				DestroyFollowingElestral();
			}
			if (TeamStatList.IsValidIndex(SlotToMoveTo) && TeamStatList.IsValidIndex(ElestralToMove)) {
				TeamStatList.Swap(ElestralToMove, SlotToMoveTo);
			}
			CreateFollowingElestral();
		}
	}
}

bool UAC_ElestralsTeamComponent::CheckTeamFaintedStatus()
{
	hasElestralsLeftAlive = false;

	for (FElestralStats stat : TeamStatList) 
	{
		if (stat.ElestralCurrentHealth > 0)
		{
			hasElestralsLeftAlive = true;
		}
	}

	return hasElestralsLeftAlive;
}

