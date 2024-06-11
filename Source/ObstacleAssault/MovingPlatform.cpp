// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	FString name = GetName();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	Rotate(DeltaTime);
}

void AMovingPlatform::Move(float DeltaTime)
{
	if (ShouldPlatformReturn()) {
		// Find the new StartLocation w/o over-shooting
		FVector moveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + moveDirection * MoveDistance;

		SetActorLocation(StartLocation);

		// Reverse direction
		PlatformVelocity = -PlatformVelocity;
	}
	else {
		SetActorLocation(GetActorLocation() + PlatformVelocity * DeltaTime);
	}
}

void AMovingPlatform::Rotate(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMovedFunction() > MoveDistance;
}

float AMovingPlatform::GetDistanceMovedFunction() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

