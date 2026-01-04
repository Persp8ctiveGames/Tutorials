// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Engine/StaticMesh.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values

AMyActor::AMyActor() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create and attach the cube mesh component
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    // Find and set the default engine cube mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

    if (CubeMeshAsset.Succeeded()) {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }

    CubeMesh->SetVisibility(true);
    CubeMesh->SetHiddenInGame(false);
    CubeMesh->SetMobility(EComponentMobility::Movable);
    CubeMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

    // Tutorial notes: You can try to comment or uncomment me.
    // if (CubeMesh) {
    //     UMaterialInterface *Mat = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Engine/EngineDebugMaterials/BoneWeightMaterial.BoneWeightMaterial")));
    //     if (Mat) {
    //         CubeMesh->SetMaterial(0, Mat);
    //     }
    // }
}

// Material will be loaded at runtime in OnConstruction
// Called when actor is constructed (in editor or during gameplay)
void AMyActor::OnConstruction(const FTransform &Transform) {
    Super::OnConstruction(Transform);

    // Tutorial notes: You can try to comment or uncomment me.
    // if (CubeMesh) {
    //     UMaterialInterface *Mat = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Engine/EngineDebugMaterials/BoneWeightMaterial.BoneWeightMaterial")));
    //     if (Mat) {
    //         CubeMesh->SetMaterial(0, Mat);
    //     }
    // }
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() {
    Super::BeginPlay();

    // Load and set material at runtime
    // if (CubeMesh) {
    //     UMaterialInterface *Mat = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Engine/EngineDebugMaterials/BoneWeightMaterial.BoneWeightMaterial")));
    //     if (Mat) {
    //         CubeMesh->SetMaterial(0, Mat);
    //     }
    // }

    // Set timer to print HelloWorld every 5 seconds
    GetWorldTimerManager().SetTimer(DebugMessageTimerHandle, this, &AMyActor::PrintDebugMessage, 1.0f, true);
}

void AMyActor::PrintDebugMessage() {
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("HelloWorld"));
    }
}

// void AMyActor::PrintDebugMessage2() {
//     if (GEngine) {
//         GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("HelloWorld2"));
//     }
// }

// Called every frame
void AMyActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
