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

    FVector LocalVector = MyVector;
    LocalVector.Z += 100;
    MyVector.Y++;
    SetActorLocation(LocalVector);
}
