
#include "UETutorial.h"
#include "BatteryPickup.h"

// Sets default values
ABatteryPickup::ABatteryPickup()
{
	PowerLevel = 150.0f;
}

void ABatteryPickup::OnPickedUp_Implementation()
{
	Super::OnPickedUp_Implementation();

	Destroy();
}


