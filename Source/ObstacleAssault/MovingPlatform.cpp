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
	FVector currentLocation = GetActorLocation();

	currentLocation += PlatformVelocity * DeltaTime;
	SetActorLocation(currentLocation);
	
	float distanceTraveled = FVector::Dist(StartLocation, currentLocation);
	if (distanceTraveled > MoveDistance) {
		// Find the new StartLocation w/o over-shooting
		FVector moveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + moveDirection * MoveDistance;

		//UE_LOG(LogTemp, Warning, TEXT("Overshot by: %f"), distanceTraveled - MoveDistance)

		SetActorLocation(StartLocation);

		// Reverse direction
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::Rotate(float DeltaTime)
{
	// Do Stuff
}

