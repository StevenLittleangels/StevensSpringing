// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define OUT // defined unreal macro OUT that does nothing

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

void UGrabber::FindPhysicsHandleComponent()
{
	/// look for attached physics handler
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) {
		// found physics yay
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s has no physics handler!"), *GetOwner()->GetName()); //"let's not get into any more detail on that, you know you need to put a star" no I don't! it's not like my solution was exactly the same except for the * which you're so casually dismissing as if it's obvious and I don't know the fuck is going on, I mean fuck it's not like I just spent 90 minutes trying to fix the fucking error that came up when I did the previous lesson to reset the project AND I STILL DON'T KNOW WHAT THE FUCK HAPPENED AND WHY BOTH VS AND UNDREAL WOULD REFUSE TO REBUILD THE FUCKING DLL! FOUR TIMES! AND I DON'T EVEN KNOW WHY NOW IT WORKS AND I
	}
}
void UGrabber::SetupInputComponent()
{
	///look for input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("%s has input"), *GetOwner()->GetName());
		///bind input action
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s has no input!"), *GetOwner()->GetName());
	}
}
void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("grab pressed"));

	/// LINE TRACE	try to reach any actors with physics body collision channel
	GetFirstPhysicsBodyInReach();
	/// if we hit something then attach a physics handle
	// TODO attach physics handle

}
void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("grab released"));
	// TODO release physics
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if physics handle is attached
		// move attached object

	
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	/// get player viewpoint this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector GrabReach = PlayerViewPointRotation.Vector() * Reach; // I'm an idiot and forgot to MULTIPLY by the reach, as per the slide 5 minutes ago. sigh.
	FVector LineTraceEnd = PlayerViewPointLocation + GrabReach;



	/// setup query parameters
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	/// raycast out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	/// see what is hit

	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("%s is being hit."), *(ActorHit->GetName()));
	}

	return FHitResult();
}
