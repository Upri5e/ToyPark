// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class StaticMeshComponent;
class CameraComponent;

UCLASS()
class TOYPARK_API APlayerPawn : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* bat;

	UPROPERTY(EditAnywhere, Category = "Components")
	UCameraComponent* Camera;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	APlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
