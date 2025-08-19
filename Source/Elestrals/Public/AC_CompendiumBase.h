// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CH_ElestralBase.h"
#include "AC_CompendiumBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELESTRALS_API UAC_CompendiumBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_CompendiumBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*The list of ALL obtainable Elestral classes in the game that will show up in the Compendium*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compendium Data")
		TArray<UClass*> TotalElestralClassList;

	/*The list of all currently obtained Elestral classes by the player character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compendium Data")
		TArray<UClass*> ObtainedElestralClasses;

	/*Populates TotalElestralClassList array with all elestral subclasses*/
	UFUNCTION(BlueprintCallable)
		void PopulateCompendium();
};
