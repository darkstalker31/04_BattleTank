// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movment and +1 is max up movement
	void Rotate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinRotationDegree = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotationDegree = 360;
	
	
};
