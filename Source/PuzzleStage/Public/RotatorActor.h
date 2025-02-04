#pragma once

#include "CoreMinimal.h"
#include "DynamicActor.h"
#include "RotatorActor.generated.h"

UCLASS()
class PUZZLESTAGE_API ARotatorActor : public ADynamicActor
{
	GENERATED_BODY()
	
public:	
	ARotatorActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector RotateDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

};
