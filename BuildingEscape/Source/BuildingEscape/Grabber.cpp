// Copyright is mine 2016

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get player viewpoint this tick
	FVector PlayerViewPointLocation;
	FRotator PlaverViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,//Using OUT allows us to remind ourselves that these parameters will be changed
		OUT PlaverViewPointRotation
	);
	// TODO Log out to test
	UE_LOG(LogTemp, Warning, TEXT("Location is %s,Rotation is %s"),
		*PlayerViewPointLocation.ToString(),
		*PlaverViewPointRotation.ToString());
	//Draw a red trace in the world to visualize
	FVector LineTraceEnd = PlayerViewPointLocation + PlaverViewPointRotation.Vector() * Reach; 
	//UE_LOG(LogTemp, Warning, TEXT("View point rotation is %s"), *PlaverViewPointRotation.ToString());
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0)
		, false,
		0.f,
		0.f,
		10.f
	);
	// Ray-cast out to reach distance

	// See what we hit

}
