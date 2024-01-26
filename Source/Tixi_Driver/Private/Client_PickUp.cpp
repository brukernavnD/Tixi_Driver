// Fill out your copyright notice in the Description page of Project Settings.


#include "Client_PickUp.h"

// Sets default values
AClient_PickUp::AClient_PickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bActive = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void AClient_PickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClient_PickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClient_PickUp::Interacted()
{
	bActive = false;
	SetActorHiddenInGame(true);

}

bool AClient_PickUp::GetActive() const
{
	return bActive;
}

