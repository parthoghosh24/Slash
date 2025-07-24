// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EchoAnimInstance.generated.h"

class AEcho;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class SLASH_API UEchoAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	AEcho* Echo;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UCharacterMovementComponent* EchoMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool IsFalling;
	
};
