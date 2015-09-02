// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.h"
#include "SpawnVolume.generated.h"


UCLASS()
class UETUTORIAL_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleInstanceOnly, Category = Spawning)
	UBoxComponent * WhereToSpawn;

	UPROPERTY(EditAnywhere, Category = Spawning)
	UClass * WhatToSpawn;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Spawning)
	float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Spawning)
	float SpawnDelayRangeHigh;
	
	UFUNCTION(BlueprintPure, Category = Spawning)
	FVector GetRandomPointInVolume();

	void EnableSpawning();

	void DisableSpawning();

private:

	float GetRandomSpawnDelay();

	float SpawnDelay;

	void SpawnPickup();

	float SpawnTime;

	bool bSpawningEnabled;
	
};
