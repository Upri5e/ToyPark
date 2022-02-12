// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class SceneComponent;
class StaticMeshComponent;
class CameraComponent;

UCLASS()
class TOYPARK_API APlayerPawn : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* bat;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	bool bCanLook;

	UFUNCTION()
	void ToggleLook(bool canLook);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	APlayerPawn();
	
	UFUNCTION()
	void MoveForward(float value);	
	UFUNCTION()
	void MoveRight(float value);
	UFUNCTION()
	void MoveUp(float value);
	UFUNCTION()
	void LookUp(float value);
	UFUNCTION()
	void LookRight(float value);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, Category = "Input")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, Category = "Input")
	float LookSensitivity;
};
