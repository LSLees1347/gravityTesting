// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetCharacterMovementComponent.h"

void UPlanetCharacterMovementComponent::UpdateGravityDirection(const FVector& NewGravityDir)
{
	SetGravityDirection(NewGravityDir);
}
