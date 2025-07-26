// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EchoAnimInstance.h"
#include "Characters/Echo.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UEchoAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Echo =  Cast<AEcho>(TryGetPawnOwner());

	if (Echo)
	{
		EchoMovement =  Echo->GetCharacterMovement();
	}
	
}

void UEchoAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (EchoMovement)
	{
		
		GroundSpeed = UKismetMathLibrary::VSizeXY(EchoMovement->Velocity);
		IsFalling = EchoMovement->IsFalling();
		CharacterState = Echo->GetCharacterState();
	}

}
