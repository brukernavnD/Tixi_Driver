// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TIXI_DRIVER_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	//constructor
	UPlayerMovementComponent();

	//steering sensitivity float curve
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	UCurveFloat* SteeringSensitivity = nullptr;

	//movement input vector acceleration float curve
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	UCurveFloat* AccelerationCurve = nullptr;

	//the minimum dot product we must have to turn the car left or right at a given fraction of maximum speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	UCurveFloat* MinimumDotProductCurve = nullptr;

	//the minimum speed we must be moving at to turn the car left or right
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinimumSpeed = 100.f;

	//overrides
	virtual void AddInputVector(FVector WorldVector, bool bForce) override;
	virtual float GetMaxAcceleration() const override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
