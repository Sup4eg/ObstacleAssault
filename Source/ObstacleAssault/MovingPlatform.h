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

private:
    UPROPERTY(EditAnywhere, Category = "Moving")
    FVector PlatformVelocity = FVector(100, 0, 0);

    UPROPERTY(EditAnywhere, Category = "Moving")
    float MovedDistance = 100.f;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    FRotator RotationVelocity;

    FVector StartLocation;

    void MovePlatform(float DeltaTime);
    void RotatePlatform(float DeltaTime);
    bool ShouldPlatformReturn() const;
    float GetDistanceMoved() const;
};
