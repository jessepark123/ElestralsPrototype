// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_CasterBase.h"

// Sets default values
ACH_CasterBase::ACH_CasterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ElestralTeamComponent = CreateDefaultSubobject<UAC_ElestralsTeamComponent>(TEXT("ElestralTeamComponent"));
}

// Called when the game starts or when spawned
void ACH_CasterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACH_CasterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACH_CasterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

