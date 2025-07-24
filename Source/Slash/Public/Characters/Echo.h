// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Echo.generated.h"

class UInputAction;
class UInputMappingContext;
class UPawnMovementComponent;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

UCLASS()
class SLASH_API AEcho : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEcho();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* EquipAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* EchoMappingContext;

	UPROPERTY(VisibleAnywhere)
	UPawnMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Input")
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = "Input")
	UGroomComponent* Eyebrows;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void HandleJump();
	void Equip();
	void Attack();
};
