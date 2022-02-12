// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"

#include <ThirdParty/openexr/Deploy/OpenEXR-2.3.0/OpenEXR/include/ImathMath.h>

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	bat = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bat"));
	bat->SetupAttachment(Camera);
}

void APlayerPawn::MoveForward(float value)
{
	FVector offset =  Camera->GetForwardVector() * (value * MoveSpeed);
	AddActorWorldOffset(offset);
}

void APlayerPawn::MoveRight(float value)
{
	FVector offset =  Camera->GetRightVector() * (value * MoveSpeed);
	AddActorWorldOffset(offset);
}

void APlayerPawn::MoveUp(float value)
{
	FVector offset =  Camera->GetUpVector() * (value * MoveSpeed);
	AddActorWorldOffset(offset);
}

void APlayerPawn::LookUp(float value)
{
	if(bCanLook)
		Camera->AddRelativeRotation(FRotator(value * LookSensitivity, 0, 0));
}

void APlayerPawn::LookRight(float value)
{
	if(bCanLook)
		Camera->AddRelativeRotation(FRotator(0, value * LookSensitivity, 0));
}

void APlayerPawn::ToggleLook(bool canLook)
{
	bCanLook = canLook;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, const bool);
	PlayerInputComponent->BindAction<FCustomInputDelegate>("LookAround", IE_Pressed, this, &APlayerPawn::ToggleLook, true);
	PlayerInputComponent->BindAction<FCustomInputDelegate>("LookAround", IE_Released, this, &APlayerPawn::ToggleLook, false);

	PlayerInputComponent->BindAxis("LookUp", this, &APlayerPawn::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerPawn::LookRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPawn::MoveUp);
}

