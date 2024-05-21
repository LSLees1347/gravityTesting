// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetaryCharacterMovement.h"

void UPlanetaryCharacterMovement::UpdateGravityDirection(const FVector& NewGravityDir)
{
	SetGravityDirection(NewGravityDir);
}
