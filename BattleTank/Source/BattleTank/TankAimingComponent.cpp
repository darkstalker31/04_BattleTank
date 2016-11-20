// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		// caluc correctly
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	
		MoveBarrel(AimDirection);
			// have barrel follow crosshair at a variable rate, which is slower than mouse speed
	//	auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" Aim found"))
	}
	else
	{
	//	auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" No Aim solve found"))
	}
		// if no solution found

};

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	// work out difference between currect barrel rotation and aim direction
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;

//	UE_LOG(LogTemp, Warning, TEXT(" AimAsRotator %s"), *AimAsRotator.ToString())

		Barrel->Elevate(5);
}