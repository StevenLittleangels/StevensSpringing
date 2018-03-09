// Fill out your copyright notice in the Description page of Project Settings.

#include "NewActorComponentOpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

#define OUT

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
	
}

void UNewActorComponentOpenDoor::OpenDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UNewActorComponentOpenDoor::CloseDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}



// Called every frame
void UNewActorComponentOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll Trigger Volume every frame
	if (GetTotalMassOfActorsOnPlate() > 50.0f) { // TODO change into a parameter
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}
}

float UNewActorComponentOpenDoor::GetTotalMassOfActorsOnPlate() {
	float TotalMass = 0.0f;

	//find overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	//iterate through their masses

	return TotalMass;
}