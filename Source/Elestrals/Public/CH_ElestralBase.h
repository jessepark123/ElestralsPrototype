// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AC_ElestralsData.h"
#include "ElestralsSkillTreeComponent.h"
#include "CH_ElestralBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class ELESTRALS_API ACH_ElestralBase : public ACharacter
{
	GENERATED_BODY()
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;

	/* Light Attack Action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LightAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* HeavyAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* UltimateAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* BlockAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* SwapAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LockOnAction;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAC_ElestralsData* ElestralDataComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UElestralsSkillTreeComponent* ElestralSkillTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ElestralHitMontage;

	/*The team component that spawned this Elestral*/
	//UPROPERTY(EditAnywhere,BlueprintReadWrite)
	//	UAC_ElestralsTeamComponent* TeamComponentSpawnedFrom;

	// Activates when elestral is locked on during combat
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isLockedOn = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACharacter* OwningCharacter;

	// Sets default values for this character's properties
	ACH_ElestralBase();

	ACH_ElestralBase(ACharacter* CharRef);

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for Light Attack input */
	void LightAttack(const FInputActionValue& Value);

	/** Called for Heavy Attack input */
	void HeavyAttack(const FInputActionValue& Value);

	/** Called for Ultimate Attack input */
	void UltimateAttack(const FInputActionValue& Value);

	/** Called for Dodge input */
	void Dodge(const FInputActionValue& Value);

	/** Called for Block input */
	void Block(const FInputActionValue& Value);

	/** Called for Swap input */
	void Swap(const FInputActionValue& Value);

	/** Called for Lock On input */
	void LockOn(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*Sets the values of this Elestral to these input params (PASS THESE VALUES FROM THE PLAYER CHARACTER'S ELESTRALSTEAMCOMPONENT)
	Also this shouldn't really need to be called in BP ideally*/
	UFUNCTION(BlueprintCallable)
		void SetupElestralData(FElestralStats inStatStruct);

	/*Call whenever the Elestral needs to have its stats refreshed to the values contained within the struct (i.e. setting charmovespeed to the speed stat)*/
	UFUNCTION(BlueprintCallable)
		void RefreshStructDataImplementation();

	UFUNCTION(BlueprintCallable)
		void SetElestralOwner(ACharacter* OwningActor);

	/*Called from spawnfollowingelestral event, add functionality in blueprint*/
	UFUNCTION(BlueprintImplementableEvent)
		void Initialize(ACharacter* OwnerRef);

	/*/*Called when Elestral is hit by an attack 
	UFUNCTION(BlueprintImplementableEvent)
		void HitByAttack(float HitPauseTime, float HitStunTime, float LaunchMult);*/
};
