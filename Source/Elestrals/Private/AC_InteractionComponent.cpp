// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_InteractionComponent.h"

// Sets default values for this component's properties
UAC_InteractionComponent::UAC_InteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_InteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_InteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UAC_InteractionComponent::CreateInteractionTrigger(FVector TriggerSize, FVector TriggerStart, FVector TriggerEnd, FQuat TriggerRot)
{
	FCollisionShape InteractionBox = FCollisionShape::MakeBox(TriggerSize);

	TArray<FHitResult> HitResults; 

	if (GetWorld()->SweepMultiByChannel(HitResults, TriggerStart, TriggerEnd, TriggerRot, ECC_Visibility, InteractionBox))
	{
		for (const FHitResult HitResult : HitResults)
		{
			if (HitResult.GetActor()->GetComponentByClass<UAC_InteractionComponent>()->IsValidLowLevel())
			{
				return HitResult.GetActor();
			}
		}
	}

	
	return nullptr;

}

