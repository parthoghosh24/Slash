// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "InputActionValue.h"
#include "Echo.generated.h"

class UInputAction;
class UInputMappingContext;
class UPawnMovementComponent;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;
class AWeapon;
class UBoxComponent;



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

	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite)
	EActionState ActionState = EActionState::EAS_Unoccupied;

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

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	/*Animation montages*/

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedWeapon;

	void PlayAttackMontage();
	void PlayEquipMontage(const FName& SectionName);

	/*End of montages*/

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	UBoxComponent* FootBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* FootBoxTraceStart;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* FootBoxTraceEnd;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void HandleJump();
	void EKeyPressed();
	void Attack();
	

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	bool CanAttack() const;
	bool CanArm() const;
	bool CanDisarm() const;

	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void SetBoxCollsion(ECollisionEnabled::Type CollisonEnabled);

};
