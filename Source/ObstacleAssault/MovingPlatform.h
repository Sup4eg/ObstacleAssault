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

    UPROPERTY(EditAnywhere)
    int32 MyInt = 99;

    UPROPERTY(EditAnywhere)
    int32 InputA = 0;

    UPROPERTY(EditAnywhere)
    int32 InputB = 0;

    UPROPERTY(EditAnywhere)
    int32 APlusB = 0;

    UPROPERTY(EditAnywhere)
    float InputFloatA = 0.f;

    UPROPERTY(EditAnywhere)
    float InputFloatB = 0.f;

    UPROPERTY(EditAnywhere)
    float APlusBFloat = 0.f;

    UPROPERTY(EditAnywhere)
    bool MyBool = true;
};
