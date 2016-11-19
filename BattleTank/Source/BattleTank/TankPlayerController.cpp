// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

// tick
	// super
		// aimTowardsCrosshair();

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; // out parameter

	if (GetSightRayHitLocation(HitLocation)) //  has side effect, is going to line trace
	{
	// reutrn an out parameter, true if hit landscape

//	UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	// get world location of linetrace through crosshair, if it hits

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find the crosshair postiion in pixel coords
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());
	// de-project the screen position of crosshair to a world direction.
	// line-trace along the look direction and see what we hit up to max range.
	return true;
}