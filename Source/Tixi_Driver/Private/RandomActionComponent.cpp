// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomActionComponent.h"
#include "Kismet/KismetArrayLibrary.h"

URandomActionComponent::URandomActionComponent()
{
}

void URandomActionComponent::BeginPlay()
{
	//call the parent implementation
	Super::BeginPlay();

	//shuffle the array
	if (bRandomOrder)
	{
		ShuffleActions();
	}

	//do the first action
	DoNextAction();
}

bool URandomActionComponent::IsArrayValid() const
{
	return false;
}

bool URandomActionComponent::IsIndexValid(int Index) const
{
	return false;
}

float URandomActionComponent::GetActionDuration() const
{
	return 0.0f;
}

void URandomActionComponent::ShuffleActions()
{

}
void URandomActionComponent::DoAction()
{

}

float URandomActionComponent::GetDelay(const float Min, const float Max, const float FixedDelay) const
{
	//check if we want to use a random delay
	if (bRandomDelay)
	{
		//return a random delay
		return FMath::RandRange(GetActionDuration() + Min, Max);
	}

	//return the fixed delay
	return FixedDelay;
}

void URandomActionComponent::DoNextAction()
{
	//check if our array is invalid
	if (!IsArrayValid())
	{
		//print error message
		UE_LOG(LogTemp, Error, TEXT("invalid array for %s"), *GetName());

		//return
		return;
	}

	//do the action
	DoAction();

	//increment the index
	CurrentIndex++;

	//set the timer
	GetWorld()->GetTimerManager().SetTimer(ActionTimerHandle, this, &URandomActionComponent::DoNextAction, GetDelay(MinDelay, MaxDelay, FirstDelay), false);

	//check if we reached the end of the array
	if (!IsIndexValid(CurrentIndex))
	{
		return;
	}

	//check if we want to loop the dialogue
	if (bLoop)
	{
		//reset the index
		CurrentIndex = 0;

		//shuffle the array
		if (bRandomOrder)
		{
			ShuffleActions();
		}

		return;
	}

	//clear the timer
	GetWorld()->GetTimerManager().ClearTimer(ActionTimerHandle);

	//destroy the component
	DestroyComponent();
}