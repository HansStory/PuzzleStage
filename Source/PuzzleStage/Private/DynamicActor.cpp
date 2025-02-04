#include "DynamicActor.h"

ADynamicActor::ADynamicActor()
{
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/EditorMeshes/AssetViewer/Floor_Mesh.Floor_Mesh'"));

	//if (MeshAsset.Succeeded())
	//{
	//	StaticMesh->SetStaticMesh(MeshAsset.Object);
	//}
}

void ADynamicActor::BeginPlay()
{
	Super::BeginPlay();

}

void ADynamicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
