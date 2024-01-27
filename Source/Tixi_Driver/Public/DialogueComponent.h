// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RandomActionComponent.h"
#include "Components/ActorComponent.h"
#include "DialogueComponent.generated.h"


UCLASS()
class TIXI_DRIVER_API UDialogueComponent : public URandomActionComponent
{
	GENERATED_BODY()

public:

	//constructor
	UDialogueComponent();

	//array of dialogue audio files
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	TArray<USoundBase*> Dialogue = TArray<USoundBase*>();

	//override the random action component functions
	virtual bool IsArrayValid() const override;
	virtual bool IsIndexValid(const int Index) const override;
	virtual float GetActionDuration() const override;
	virtual void ShuffleActions() override;
	virtual void DoAction() override;
};
