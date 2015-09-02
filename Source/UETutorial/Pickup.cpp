// Fill out your copyright notice in the Description page of Project Settings.

#include "UETutorial.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// pickup activate on creation
	bIsActive = true;

	BaseCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BaseSphereComponent"));
	RootComponent = BaseCollisionComponent;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

	// enable physics
	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->AttachTo(RootComponent);
}

void APickup::OnPickedUp_Implementation()
{
	// no default behavior
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

