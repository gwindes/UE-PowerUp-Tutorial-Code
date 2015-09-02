// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class UETUTORIAL_API AGameHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	UFont* HUDFont;

	virtual void DrawHUD() override;
};
