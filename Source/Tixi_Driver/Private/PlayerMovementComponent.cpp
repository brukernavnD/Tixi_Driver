// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
	RotationRate = FRotator(40, 40, 40);
}

void UPlayerMovementComponent::AddInputVector(FVector WorldVector, bool bForce)
{
	//check if the world vector is zero
	if (WorldVector == FVector::ZeroVector)
	{
		return;
	}

	////check if the dot product of the world vector and the forward vector is greater than the minimum dot product
	//if (const float DotProduct = FVector::DotProduct(WorldVector.GetSafeNormal(), GetCharacterOwner()->GetMesh()->GetComponentRotation().Vector()); FMath::Abs(DotProduct) > MinimumDotProduct)
	//{
	//	//print the dot product
	//	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, FString::Printf(TEXT("Dot product: %f"), DotProduct));

	//	//check if the dot product is less than 0
	//	if (DotProduct < 0)
	//	{
	//		//add the input vector in the opposite direction we're facing
	//		Super::AddInputVector(GetCharacterOwner()->GetMesh()->GetForwardVector() * -1 * SteeringSensitivity->GetFloatValue(DotProduct), bForce);

	//		bSetRotation = false;

	//		return;
	//	}

	//	if (FVector::DotProduct(Velocity.GetSafeNormal(), GetCharacterOwner()->GetMesh()->GetComponentRotation().Vector()) > 0.5f)
	//	{
	//		bSetRotation = false;

	//		//call the parent implementation
	//		Super::AddInputVector(WorldVector.GetSafeNormal() * 0.001f, bForce);
	//	}
	//	else
	//	{
	//		bSetRotation = true;

	//		//call the parent implementation
	//		Super::AddInputVector(WorldVector.GetSafeNormal() * SteeringSensitivity->GetFloatValue(DotProduct), bForce);
	//	}

	//	////set the rotation of the mesh
	//	//GetCharacterOwner()->GetMesh()->SetWorldRotation(WorldVector.GetSafeNormal().Rotation());
	//}

	//get the dot product of the world vector and the forward vector
	const float DotProduct = FVector::DotProduct(WorldVector.GetSafeNormal(), GetCharacterOwner()->GetMesh()->GetComponentRotation().Vector());

	//check if our current speed is less than minimum speed for turning

	//call the parent implementation
	Super::AddInputVector(WorldVector.GetSafeNormal() * SteeringSensitivity->GetFloatValue(DotProduct), bForce);
	
}

float UPlayerMovementComponent::GetMaxAcceleration() const
{
	return Super::GetMaxAcceleration() * AccelerationCurve->GetFloatValue(Velocity.Size() / GetMaxSpeed());
}

void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//call the parent implementation
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//check if speed is less than minimum speed
	if (const float DotProduct = FVector::DotProduct(Velocity.GetSafeNormal(), GetCharacterOwner()->GetMesh()->GetComponentRotation().Vector()); DotProduct < MinimumDotProductCurve->GetFloatValue(Velocity.Size() / GetMaxSpeed()) || (DotProduct < 0 && FMath::Abs(DotProduct) > MinimumDotProductCurveReverse->GetFloatValue(Velocity.Size() / GetMaxSpeed())))
	{
		//set the velocity to be either forwards or backwards based on the dot product
		Velocity = GetCharacterOwner()->GetMesh()->GetComponentRotation().Vector() * Velocity.Size() * FMath::Sign(DotProduct);

		//prevent further execution
		return;
	}

	//set the rotation of the mesh
	GetCharacterOwner()->GetMesh()->SetWorldRotation(Velocity.Rotation());
}
