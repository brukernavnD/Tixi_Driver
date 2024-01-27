// Fill out your copyright notice in the Description page of Project Settings.


#include "Client_PickUp.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
AClient_PickUp::AClient_PickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AClient_PickUp::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AClient_PickUp::OnOverlapEnd);

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

void AClient_PickUp::OnOverlapBegin(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherCamp, int32 OtherBodyIndex, bool BFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "OverLap Begin Function Called");

}

void AClient_PickUp::OnOverlapEnd(UPrimitiveComponent* OverLappedComp, AActor* OtherActor, UPrimitiveComponent* OtherCamp, int32 OtherBodyIndex)
{

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "OverLap End Function Called");
}
