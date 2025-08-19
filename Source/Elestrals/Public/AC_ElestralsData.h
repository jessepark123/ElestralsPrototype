// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ElestralsMoveBase.h"
#include "Elements.h"
#include "AC_ElestralsData.generated.h"

USTRUCT(BlueprintType)
struct FElestralBaseStats
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Stats")
		int ElestralBaseHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Stats")
		int ElestralBaseSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Stats")
		int ElestralBaseAttack;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Stats")
		int ElestralBaseDefense;

};
USTRUCT(BlueprintType)
struct FElestralStats
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString ElestralName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EElements ElestralElement;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EElements ElestralSecondElement;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralCurrentHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralAttack;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralDefense;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralCurrentXP;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralTotalXPToNextLevel;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralTotalXP;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralLevel;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralXPGrowthModifier;


		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ElestralBondPercentage;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		TSubclassOf<ACH_ElestralBase> ElestralClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		UTexture2D* ElestralDisplayImage;

		UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<UElestralsMoveBase*> CurrentActiveLightCombo;

		UPROPERTY(BlueprintReadWrite, Category = "Data")
		UElestralsMoveBase* CurrentActiveHeavyAttack;

		UPROPERTY(BlueprintReadWrite, Category = "Data")
		UElestralsMoveBase* CurrentActiveUltimateAttack;

		UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<UElestralsMoveBase*> AllInstantiatedMoves;


	
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELESTRALS_API UAC_ElestralsData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_ElestralsData();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FElestralStats ElestralStats;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FElestralBaseStats ElestralBaseStats;

	UFUNCTION(BlueprintCallable)
		TArray<UElestralsMoveBase*> GetElestralCurrentActiveLightCombo();

	UFUNCTION(BlueprintCallable)
		UElestralsMoveBase* GetElestralCurrentHeavyAttack();

	UFUNCTION(BlueprintCallable)
		UElestralsMoveBase* GetElestralCurrentUltimateAttack();

	UFUNCTION(BlueprintCallable)
		FString GetElestralName();

	UFUNCTION(BlueprintCallable)
		EElements GetElestralElement();

	UFUNCTION(BlueprintCallable)
		float GetElestralHealth();

	UFUNCTION(BlueprintCallable)
		float GetElestralCurrentHealth();

	UFUNCTION(BlueprintCallable)
		float GetElestralSpeed();

	UFUNCTION(BlueprintCallable)
		float GetElestralAttack();

	UFUNCTION(BlueprintCallable)
		float GetElestralDefense();

	UFUNCTION(BlueprintCallable)
		FElestralStats GetElestralStats();

	UFUNCTION(BlueprintCallable)
		UTexture2D* GetElestralDisplayImage();

	UFUNCTION(BlueprintCallable)
		TSubclassOf<ACH_ElestralBase> GetElestralClass();

	UFUNCTION(BlueprintCallable)
		TArray<UElestralsMoveBase*> SetElestralCurrentActiveLightCombo(TArray<UElestralsMoveBase*> inLightCombo);

	UFUNCTION(BlueprintCallable)
		UElestralsMoveBase* SetElestralCurrentHeavyAttack(UElestralsMoveBase* inHeavyAttack);

	UFUNCTION(BlueprintCallable)
		UElestralsMoveBase* SetElestralCurrentUltimateAttack(UElestralsMoveBase* inUltimateAttack);

	UFUNCTION(BlueprintCallable)
		FString SetElestralName(FString inName);

	UFUNCTION(BlueprintCallable)
		EElements SetElestralElement(EElements inElement);

	UFUNCTION(BlueprintCallable)
		float SetElestralHealth(float inHealth);

	UFUNCTION(BlueprintCallable)
		float SetElestralCurrentHealth(float inCurrentHealth);

	UFUNCTION(BlueprintCallable)
		float SetElestralSpeed(float inSpeed);

	UFUNCTION(BlueprintCallable)
		float SetElestralAttack(float inATK);

	UFUNCTION(BlueprintCallable)
		float SetElestralDefense(float inDEF);

	UFUNCTION(BlueprintCallable)
		FElestralStats SetElestralStats(FElestralStats inStats);

	UFUNCTION(BlueprintCallable)
		UTexture2D* SetElestralDisplayImage(UTexture2D* TextureToSet);

	UFUNCTION(BlueprintCallable)
		TSubclassOf<ACH_ElestralBase> SetElestralClass(TSubclassOf<ACH_ElestralBase> inClass);

		/*Adds experience to Elestral, returns true if the Elestral leveled up from this experience*/
	UFUNCTION(BlueprintCallable)
		bool AddExperienceToElestral(int ExperienceToAdd);

		/*Calculates the current stats of the Elestral from the base stats and sets them in the Data Component*/
	UFUNCTION(BlueprintCallable)
		void CalculateElestralStats();
		
};
