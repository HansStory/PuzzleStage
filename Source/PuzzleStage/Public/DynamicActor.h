// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicActor.generated.h"

UCLASS()
class PUZZLESTAGE_API ADynamicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADynamicActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dynamic Actor")
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dynamic Actor")
	UStaticMeshComponent* StaticMesh;
};
