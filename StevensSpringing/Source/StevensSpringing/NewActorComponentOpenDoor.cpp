// Fill out your copyright notice in the Description page of Project Settings.

#include "NewActorComponentOpenDoor.h"
#include "Gameframework/Actor.h"


// Sets default values for this component's properties
UNewActorComponentOpenDoor::UNewActorComponentOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNewActorComponentOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FRotator NewRotation = FRotator(0.f, 70.f, 0.f);
	auto Owner = GetOwner()->SetActorRotation(NewRotation);

}


// Called every frame
void UNewActorComponentOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

