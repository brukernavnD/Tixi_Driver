// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueComponent.h"
#include "Kismet/GameplayStatics.h"

UDialogueComponent::UDialogueComponent()
{
}

bool UDialogueComponent::IsArrayValid() const
{
	return Dialogue.Num() > 0;
}

bool UDialogueComponent::IsIndexValid(const int Index) const
{
	return Dialogue.IsValidIndex(Index);
}

float UDialogueComponent::GetActionDuration() const
{
	return Dialogue[CurrentIndex]->Duration;
}

void UDialogueComponent::ShuffleActions()
{
	//get the last index
	const int32 LastIndex = Dialogue.Num() - 1;

	//iterate through the array
	for (int32 i = 0; i <= LastIndex; ++i)
	{
		//generate a random index between i and the last index and check if it's not the same as i
		if (const int32 Index = FMath::RandRange(i, LastIndex); i != Index)
		{
			//swap the elements
			Dialogue.Swap(i, Index);
		}
	}
}

void UDialogueComponent::DoAction()
{
	UGameplayStatics::PlaySound2D(GetWorld(), Dialogue[CurrentIndex]);
}

