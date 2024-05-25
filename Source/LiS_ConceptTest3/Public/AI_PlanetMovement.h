// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI_PlanetMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIS_CONCEPTTEST3_API UAI_PlanetMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAI_PlanetMovement();

	void findMoveDirection(FVector targetLocation);

	void move(FVector direction);

	APawn* PlayerPawn;
	FVector PlayerLocation;
	FVector MoveDirection;
	float Speed;

	float DT;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
