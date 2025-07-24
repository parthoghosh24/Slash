// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float RunningTime;

	UPROPERTY(EditAnywhere, Category = "Sin Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, Category = "Sin Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformSin(float Value);

	UFUNCTION(BlueprintPure)
	float TransformCos(float Value);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	template<typename T> 
	T Avg(T First, T Second);

};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return T(First + Second) / 2;
}
