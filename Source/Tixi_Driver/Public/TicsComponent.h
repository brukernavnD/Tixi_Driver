// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RandomActionComponent.h"
#include "TicsComponent.generated.h"

class ATixi_DriverCharacter;
/**
 * 
 */
UCLASS()
class TIXI_DRIVER_API UTicsComponent : public URandomActionComponent
{
	GENERATED_BODY()

public:

	//constructor
	UTicsComponent();

	//the number of different tics
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tics")
	int NumberOfTics = 4;

	//reference to the owner actor as a taxi actor
	UPROPERTY()
	ATixi_DriverCharacter* Taxi = nullptr;

	//array of tic indexes for the random action component
	TArray<int32> TicsArray = TArray<int32>();



	//overrides
	virtual void BeginPlay() override;
	virtual bool IsArrayValid() const override;
	virtual bool IsIndexValid(const int Index) const override;
	virtual float GetActionDuration() const override;
	virtual void ShuffleActions() override;
	virtual void DoAction() override;
};
