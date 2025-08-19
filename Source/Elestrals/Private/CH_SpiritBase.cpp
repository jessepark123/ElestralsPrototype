// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_SpiritBase.h"

// Sets default values
ACH_SpiritBase::ACH_SpiritBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpiritMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SpiritMeshComponent"));
}

// Called when the game starts or when spawned
void ACH_SpiritBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACH_SpiritBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACH_SpiritBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

