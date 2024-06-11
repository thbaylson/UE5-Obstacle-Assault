// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

// TODO: Try using VS Code as the course recommends for easier workflow
UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Config")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Config")
	FRotator RotationVelocity = FRotator(0, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Config")
	float MoveDistance;

	FVector StartLocation;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	// Const functions are guaranteed by the compiler to NOT change the state of the class, ie. they cannot modify members
	bool ShouldPlatformReturn() const;
	float GetDistanceMovedFunction() const;
};
