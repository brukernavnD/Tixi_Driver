// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandomActionComponent.generated.h"


UCLASS()
class TIXI_DRIVER_API URandomActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	//constructor
	URandomActionComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	bool bRandomOrder = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	bool bLoop = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	bool bRandomDelay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	float FirstDelay = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	float MinDelay = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	float MaxDelay = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actions")
	int CurrentIndex = 0;

	FTimerHandle ActionTimerHandle;

	//overrides
	virtual void BeginPlay() override;

	//virtual functions to be overridden
	virtual bool IsArrayValid() const;
	virtual bool IsIndexValid(const int Index) const;
	virtual float GetActionDuration() const;
	virtual void ShuffleActions();
	virtual void DoAction();

	float GetDelay(const float Min, const float Max, const float FixedDelay) const;

	UFUNCTION()
	void DoNextAction();
	
};
