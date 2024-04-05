// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    SetActorLocation(MyVector);
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
