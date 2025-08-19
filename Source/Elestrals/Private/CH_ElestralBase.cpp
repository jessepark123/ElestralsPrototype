// Fill out your copyright notice in the Description page of Project Settings.

#include "CH_ElestralBase.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"



// Sets default values
ACH_ElestralBase::ACH_ElestralBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	ElestralDataComponent = CreateDefaultSubobject<UAC_ElestralsData>(TEXT("ElestralDataComponent"));
	ElestralSkillTreeComponent = CreateDefaultSubobject<UElestralsSkillTreeComponent>(TEXT("ElestralSkillTreeComponent"));
	
}

ACH_ElestralBase::ACH_ElestralBase(ACharacter* CharRef)
{
	SetElestralOwner(CharRef);
}

// Called when the game starts or when spawned
void ACH_ElestralBase::BeginPlay()
{
	GetCharacterMovement()->MaxWalkSpeed = ElestralDataComponent->GetElestralSpeed(); //place this before super::beginplay so it runs before the bp for initialization reasons
	Super::BeginPlay(); //anything after this will make the bp run before

}

// Called every frame
void ACH_ElestralBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACH_ElestralBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Adding Mapping Context Successful"));
		}
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::Look);

		// Light Attack
		EnhancedInputComponent->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::LightAttack);

		// Heavy Attack
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::HeavyAttack);

		// Ultimate Attack
		EnhancedInputComponent->BindAction(UltimateAttackAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::UltimateAttack);

		// Dodge
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::Dodge);

		// Block
		EnhancedInputComponent->BindAction(BlockAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::Block);

		// Swap
		EnhancedInputComponent->BindAction(SwapAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::Swap);

		// Lock On
		EnhancedInputComponent->BindAction(LockOnAction, ETriggerEvent::Triggered, this, &ACH_ElestralBase::LockOn);

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Input Cast Succeeded"));
	}
	else
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Input Cast Failed")); 
	}

}

void ACH_ElestralBase::SetupElestralData(FElestralStats inStatStruct)
{
	ElestralDataComponent->SetElestralStats(inStatStruct);
}

void ACH_ElestralBase::RefreshStructDataImplementation()
{
	GetCharacterMovement()->MaxWalkSpeed = ElestralDataComponent->GetElestralSpeed();
	//add more lines here when using stats for other things than just setting char movespeed
}

void ACH_ElestralBase::SetElestralOwner(ACharacter* OwningActor)
{
	OwningCharacter = OwningActor;
}

void ACH_ElestralBase::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Controller was NOT NULLPTR"));
	}
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Attempted Elestral Move"));
}

void ACH_ElestralBase::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		if (!isLockedOn) {
			// add yaw and pitch input to controller
			AddControllerYawInput(LookAxisVector.X);
			AddControllerPitchInput(LookAxisVector.Y);
		}
	}
}

void ACH_ElestralBase::LightAttack(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::HeavyAttack(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::UltimateAttack(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::Dodge(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::Block(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::Swap(const FInputActionValue& Value)
{
}

void ACH_ElestralBase::LockOn(const FInputActionValue& Value)
{
}




