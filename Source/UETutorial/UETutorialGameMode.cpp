// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "UETutorial.h"
#include "UETutorialGameMode.h"
#include "UETutorialCharacter.h"
#include "SpawnVolume.h"
#include "GameHUD.h"
#include "GameHUD.h"

AUETutorialGameMode::AUETutorialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = AGameHUD::StaticClass();

	DecayRate = 0.25f;
}

void AUETutorialGameMode::Tick(float DeltaSeconds)
{
	AUETutorialCharacter * MyCharacter = Cast<AUETutorialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (MyCharacter->PowerLevel > 1.0)
	{
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.f, DeltaSeconds, DecayRate);
	}
	else
	{
		MyCharacter->PowerLevel = 0.0;
		SetCurrentState(EUETutorialGameModeState::EGameOver);
	}
}

void AUETutorialGameMode::SetCurrentState(EUETutorialGameModeState State)
{
	CurrentState = State;

	HandleNewState(State);
}

void AUETutorialGameMode::HandleNewState(EUETutorialGameModeState State)
{
	switch (State)
	{
		case EUETutorialGameModeState::EPlaying:
		{
			for (ASpawnVolume * Volume : SpawnVolumeActors)
			{
				Volume->EnableSpawning();
			}
			break;
		}
		case EUETutorialGameModeState::EGameOver:
		{
			for (ASpawnVolume * Volume : SpawnVolumeActors)
			{
				Volume->DisableSpawning();
			}
			APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			PlayerController->SetCinematicMode(true, true, true);
			break;
		}
		case EUETutorialGameModeState::EUnknown:
		default:
			break;
	}
}

void AUETutorialGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume * SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}
	
	SetCurrentState(EUETutorialGameModeState::EPlaying);
}
