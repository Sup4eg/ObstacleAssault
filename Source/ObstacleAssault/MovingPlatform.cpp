// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
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
}
