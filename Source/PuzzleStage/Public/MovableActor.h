#pragma once

#include "CoreMinimal.h"
#include "DynamicActor.h"
#include "MovableActor.generated.h"

UCLASS()
class PUZZLESTAGE_API AMovableActor : public ADynamicActor
{
	GENERATED_BODY()
	
public:	
	AMovableActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector Direction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float Speed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	bool bRandomChange;

private:
	FVector StartPos;
    FVector GetRandomDirection();

	void ChangeDirection();
};
