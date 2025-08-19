// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AC_ElestralsTeamComponent.h"
#include "AC_CompendiumBase.h"
#include "AC_PlayerInventory.h"
#include "AC_InteractionComponent.h"
#include "ElestralsCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AElestralsCharacter : public ACharacter
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

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;


	/** Compendium Display Input Action *this is NOT in the player controller because the compendium should only be accessible while possessing the player pawn* */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CompendiumAction;

public:
	/*Team Component holds the current list of team objects*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAC_ElestralsTeamComponent* ElestralTeamComponent;

	/*Compendium Component holds a list of all Elestral objects and which ones the character has ever received in their TeamComponent*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAC_CompendiumBase* CompendiumComponent;

	/*Inventory Component handles all items owned by this character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAC_PlayerInventory* InventoryComponent;
	
	/*Interaction Component handles all interactions by this character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAC_InteractionComponent* InteractionComponent;

	AElestralsCharacter();
	
	//Interact and Compendium Display inputs are extended to BP-level functionality because they are not optimization-risking events and have potential BP dependencies

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	/*Function is called when the interact button is pressed, used for both interacting with people/objects and moving through dialogue screens
	Left BP native for BP implementation for potential dependency on BP-level systems*/
	UFUNCTION(BlueprintImplementableEvent)
	void TryInteract(const FInputActionValue& Value);

	/*Function is called when the compendium display button is pressed, extended to BP-level functionality*/
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayCompendium(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

