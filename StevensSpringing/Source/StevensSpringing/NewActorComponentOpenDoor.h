// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "NewActorComponentOpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEven);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEVENSSPRINGING_API UNewActorComponentOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewActorComponentOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintAssignable)
	FDoorEven OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEven OnClose;

private:
	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr; //hey, you type stuff in visual studio and it appears magically in unreal, what sorcery

	float GetTotalMassOfActorsOnPlate();
};
