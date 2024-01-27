// Fill out your copyright notice in the Description page of Project Settings.


#include "Tixi_Driver/Public/TicsComponent.h"

#include "Tixi_Driver/Public/Tixi_DriverCharacter.h"

UTicsComponent::UTicsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTicsComponent::BeginPlay()
{
	//get the owner as an ATaxi actor
	Taxi = Cast<ATixi_DriverCharacter>(GetOwner());

	//seed the random number generator
	FGenericPlatformMath::SRandInit(time(nullptr));

	//initialize the tics array
	for (int i = 0; i < NumberOfTics; i++)
	{
		TicsArray.Add(i);
	}

	//call the parent implementation
	Super::BeginPlay();
}

bool UTicsComponent::IsArrayValid() const
{
	return true;
}

bool UTicsComponent::IsIndexValid(const int Index) const
{
	return Index >= NumberOfTics;
}

float UTicsComponent::GetActionDuration() const
{
	//return the taxi's get tic duration function
	return Taxi->CurrentTicDuration;
}

void UTicsComponent::ShuffleActions()
{
	//iterate through the tics array and swap each element
	for (int i = TicsArray.Num() - 1; i > 0; i--) {

		//get the random index
		const int j = FMath::FloorToInt(FMath::SRand() * (i + 1)) % TicsArray.Num();

		//swap the elements
        TicsArray.Swap(i, j);
    }
}

void UTicsComponent::DoAction()
{
	//check if the array is empty
	if(TicsArray.IsEmpty())
	{
		//if it is, return
		return;
	}

	//call the do tic function
	Taxi->DoTic(TicsArray[CurrentIndex]);
}
