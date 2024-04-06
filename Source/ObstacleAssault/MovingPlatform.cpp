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

    FString Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("BeginPlay: %s"), *Name);
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    MovePlatform(DeltaTime);
    RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
    FVector CurrentLocation = GetActorLocation();
    CurrentLocation += PlatformVelocity * DeltaTime;
    SetActorLocation(CurrentLocation);
    float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
    if (DistanceMoved > MovedDistance)
    {
        float OverShoot = DistanceMoved - MovedDistance;
        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f, Name of Actor: %s"), OverShoot, *GetName());

        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        StartLocation += MoveDirection * MovedDistance;
        SetActorLocation(StartLocation);
        PlatformVelocity *= -1;
    }
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
    UE_LOG(LogTemp, Display, TEXT("Rotate Platform: %s"), *GetName());
}
