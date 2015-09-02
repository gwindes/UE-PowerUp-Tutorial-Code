// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnVolume.h"
#include "UETutorialGameMode.generated.h"


enum class EUETutorialGameModeState : short
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AUETutorialGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;

	EUETutorialGameModeState GetCurrentState() const;

	AUETutorialGameMode();

	void SetCurrentState(EUETutorialGameModeState State);

	virtual void BeginPlay() override;

private:
	TArray<ASpawnVolume*> SpawnVolumeActors;

	EUETutorialGameModeState CurrentState;

	void HandleNewState(EUETutorialGameModeState State);


};

FORCEINLINE EUETutorialGameModeState AUETutorialGameMode::GetCurrentState() const
{
	return CurrentState;
}

