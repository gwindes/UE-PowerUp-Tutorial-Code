// Fill out your copyright notice in the Description page of Project Settings.

#include "UETutorial.h"
#include "GameHUD.h"
#include "UETutorialCharacter.h"
#include "UETutorialGameMode.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Kismet/GameplayStatics.h"


AGameHUD::AGameHUD(FObjectInitializer const &ObjectIntializer)
	: Super(ObjectIntializer)
{
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void AGameHUD::DrawHUD()
{
	FVector2D ScreenDim = FVector2D(Canvas->SizeX, Canvas->SizeY);

	Super::DrawHUD();

	AUETutorialCharacter * Character = Cast<AUETutorialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	FString PowerLevelString = FString::Printf(TEXT("%10.1f"), FMath::Abs(Character->PowerLevel));
	DrawText(PowerLevelString, FColor::White, 50, 50, HUDFont);

	AUETutorialGameMode * GameMode = Cast<AUETutorialGameMode>(UGameplayStatics::GetGameMode(this));

	if (GameMode->GetCurrentState() == EUETutorialGameModeState::EGameOver)
	{
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
		DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDim.X - GameOverSize.X) / 2.0f, (ScreenDim.Y - GameOverSize.Y) / 2.0f, HUDFont);
	}
}



