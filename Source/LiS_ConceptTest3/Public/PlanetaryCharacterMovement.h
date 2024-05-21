// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlanetaryCharacterMovement.generated.h"

/**
 * 
 */
UCLASS()
class LIS_CONCEPTTEST3_API UPlanetaryCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Blueprintcallable)
	void UpdateGravityDirection(const FVector& NewGravityDir);
	
};
