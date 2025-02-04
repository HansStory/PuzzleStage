#include "MovableActor.h"
#include "Math/UnrealMathUtility.h"

AMovableActor::AMovableActor()
{
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (MeshAsset.Succeeded())
    {
        StaticMesh->SetStaticMesh(MeshAsset.Object);
    }

    // �ʱⰪ ����
    StartPos = GetActorLocation();
    Direction = FVector(1, 0, 0);
    MoveSpeed = 500.0f;
    MaxRange = 100.0f;
}

void AMovableActor::BeginPlay()
{
    Super::BeginPlay();

    StartPos = GetActorLocation();
}

void AMovableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalOffset(Direction * MoveSpeed * DeltaTime);

    if (FVector::Dist(GetActorLocation(), StartPos) >= MaxRange)
    {
        UE_LOG(LogTemp, Warning, TEXT("Boundary Hit! Changing Direction."));
        ChangeDirection();
    }
}

// ������ ���� ���� ����
FVector AMovableActor::GetRandomDirection()
{
    FVector centerDirection = (StartPos - GetActorLocation()).GetSafeNormal();
    FVector randomVector = FMath::VRand();
    FVector newDirection = (centerDirection + randomVector).GetSafeNormal();

    return newDirection;
}

void AMovableActor::ChangeDirection()
{
    if (bRandomChange)
    {
        Direction = GetRandomDirection();
    }
    else
    {
        // �������̴� ������ �ݴ�������� ��ȯ
        Direction *= -1;
    }
}
