// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_ElestralsData.h"
#include "CH_ElestralBase.h"
#include "GameFramework/Character.h"
#include "AC_ElestralsTeamComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELESTRALS_API UAC_ElestralsTeamComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_ElestralsTeamComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FElestralStats> TeamStatList = TArray<FElestralStats>{};

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ACH_ElestralBase* CurrentFollowingElestral;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool hasElestralsLeftAlive;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		FElestralStats AddElestralStatsToTeam(FElestralStats StatsToAdd);

	/**Creates an Elestral based on the first struct in the team struct array*/
	UFUNCTION(BlueprintCallable)
		ACH_ElestralBase* CreateFollowingElestral();

	/**Destroys the currently following Elestral*/
	UFUNCTION(BlueprintCallable)
		void DestroyFollowingElestral();

	UFUNCTION(BlueprintCallable)
		void SwapElestralTeamPositions(int32 ElestralToMove, int32 SlotToMoveTo);

		/*Checks the whole team for whether or not they are currently fainted*/
	UFUNCTION(BlueprintCallable)
		bool CheckTeamFaintedStatus();
};
