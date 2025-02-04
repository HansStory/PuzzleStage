#include "RotatorActor.h"

ARotatorActor::ARotatorActor()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}

	RotateDirection = FVector(1, 0, 0);
	RotationSpeed = 360.0f;
}

void ARotatorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		// �ʴ� RotationSpeed��ŭ, �� �����Ӵ� (RotationSpeed * DeltaTime)��ŭ ȸ��
		FVector rotate = RotateDirection * RotationSpeed * DeltaTime;
		AddActorLocalRotation(FRotator(rotate.X, rotate.Y, rotate.Z));
	}
}

