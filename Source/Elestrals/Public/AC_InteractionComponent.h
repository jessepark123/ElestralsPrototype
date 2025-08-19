// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELESTRALS_API UAC_InteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_InteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	/*Creates the interaction trigger and returns the first actor it finds with an interaction component*/
	UFUNCTION(BlueprintCallable)
	AActor* CreateInteractionTrigger(FVector TriggerSize, FVector TriggerStart, FVector TriggerEnd, FQuat TriggerRot);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> DialogueBoxes; 
		
};
