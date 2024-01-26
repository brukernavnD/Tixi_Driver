// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Client_PickUp.generated.h"

UCLASS()
class TIXI_DRIVER_API AClient_PickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClient_PickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	void Interacted();
	bool GetActive() const;


private:
	
	UPROPERTY()
	bool bActive;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* mesh;
};
