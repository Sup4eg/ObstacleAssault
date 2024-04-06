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

    UE_LOG(LogTemp, Display, TEXT("Your message"));
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
    float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
    // Reverse direction if we've gone too far
    if (DistanceMoved > MovedDistance)
    {
        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        StartLocation += MoveDirection * MovedDistance;
        SetActorLocation(StartLocation);
        PlatformVelocity *= -1;
    }
}
