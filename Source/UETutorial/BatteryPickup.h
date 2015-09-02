// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class UETUTORIAL_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	ABatteryPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;
	
	void OnPickedUp_Implementation() override;
	
};
