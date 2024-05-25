// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_PlanetMovement.h"

// Sets default values for this component's properties
UAI_PlanetMovement::UAI_PlanetMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAI_PlanetMovement::BeginPlay()
{
	Super::BeginPlay();

	Speed = 100.0f;
	// ...
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UAI_PlanetMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DT = DeltaTime;

	// Get Player location
	PlayerLocation = PlayerPawn->GetActorLocation();
	
	findMoveDirection(PlayerLocation);
}

void UAI_PlanetMovement::findMoveDirection(FVector targetLocation)
{
	//could check if in range before changing player direction
	if (PlayerPawn)
	{
		

		// Calculate direction to player
		FVector MyActorLocation = GetOwner()->GetActorLocation();
		//normalize the vector
		FVector DirectionToPlayer = (targetLocation - MyActorLocation);

		/*
		float Magnitude = FMath::Sqrt(DirectionToPlayer.X * DirectionToPlayer.X + DirectionToPlayer.Y * DirectionToPlayer.Y + DirectionToPlayer.Z * DirectionToPlayer.Z);
		if (Magnitude > 0.001f) { // Tolerance to avoid division by zero
			DirectionToPlayer /= Magnitude;
		}
		*/

		DirectionToPlayer.Normalize();

		move(DirectionToPlayer);
	}
}

//update location of actor based on direction and speed
void UAI_PlanetMovement::move(FVector direction)
{
	if (!direction.IsZero())
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector Movement = direction * Speed * DT;
		FVector NewLocation = CurrentLocation + Movement;

		GetOwner()->SetActorLocation(NewLocation);
		
		//print location on screen 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("direction: %s"), *direction.ToString()));
	}
}

