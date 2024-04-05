// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Moving Platform")
    FVector PlatformVelocity = FVector(100, 0, 0);

    UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
    float DistanceMoved = -1.f;

    FVector StartLocation;
};
