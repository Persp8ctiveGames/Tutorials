// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class VSINTELLI_API AMyActor : public AActor {
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    AMyActor();

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called when actor is constructed (in editor or during gameplay)
    virtual void OnConstruction(const FTransform &Transform) override;

  protected:
    // The cube mesh component
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent *CubeMesh;

    // Timer handle for debug printing
    FTimerHandle DebugMessageTimerHandle;

    // Function to print debug message
    UFUNCTION()
    void PrintDebugMessage();

    // UFUNCTION()
    // void PrintDebugMessage2();
};
