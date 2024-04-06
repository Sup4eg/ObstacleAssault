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

    if (ShouldPlatformReturn())
    {
        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        StartLocation += MoveDirection * MovedDistance;
        SetActorLocation(StartLocation);
        PlatformVelocity *= -1;
    }
    else
    {
        FVector CurrentLocation = GetActorLocation();
        CurrentLocation += PlatformVelocity * DeltaTime;
        SetActorLocation(CurrentLocation);
    }
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
    AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
    return GetDistanceMoved() > MovedDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
    return FVector::Dist(StartLocation, GetActorLocation());
}
