// Fill out your copyright notice in the Description page of Project Settings.


#include "Client_DropOff.h"
#include "Components/BoxComponent.h"

// Sets default values
AClient_DropOff::AClient_DropOff()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AClient_DropOff::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AClient_DropOff::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AClient_DropOff::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClient_DropOff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClient_DropOff::OnOverlapBegin(UPrimitiveComponent* OverLappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherCamp, int32 OtherBodyIndex, bool BFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "OverLap Begin Function Called");

}

void AClient_DropOff::OnOverlapEnd(UPrimitiveComponent* OverLappedComp, AActor* OtherActor, UPrimitiveComponent* OtherCamp, int32 OtherBodyIndex)
{

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "OverLap End Function Called");
}