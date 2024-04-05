// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Move platform forwards
    // Get current location
    FVector CurrentLocation = GetActorLocation();
    // Add vector to that location
    CurrentLocation += PlatformVelocity * DeltaTime;
    // Set the location
    SetActorLocation(CurrentLocation);
    // Send platform back if gone too far
    // Check how far we've moved
    DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
}
