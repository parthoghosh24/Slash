// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Treasure.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Echo.h"

void ATreasure::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	AEcho* Echo = Cast<AEcho>(OtherActor);

	if (Echo)
	{
		if (PickupSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		}
		Destroy();
	}

}
