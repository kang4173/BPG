// Fill out your copyright notice in the Description page of Project Settings.


#include "Hole.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHole::AHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Sphere = CreateDefaultSubobject< USphereComponent>(TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_StaticMeshComponent(TEXT("StaticMesh'/Engine/VREditor/TransformGizmo/RotationHandleFull.RotationHandleFull'"));
	if (SM_StaticMeshComponent.Succeeded())
	{
		Mesh->SetStaticMesh(SM_StaticMeshComponent.Object);
		Mesh->SetRelativeRotation(FRotator(0,90,0));
		Sphere->SetWorldScale3D(FVector(10,10,10));

		Sphere->OnComponentBeginOverlap.AddDynamic(this , &AHole::OnOverlapBegin);
		Sphere->OnComponentEndOverlap.AddDynamic(this , &AHole::OnOverlapEnd);
	}
	MyTimeline=FTimeline();



}

// Called when the game starts or when spawned
void AHole::BeginPlay()
{
	Super::BeginPlay();

	Owner->sphere->GetOverlappingActors(OverlappingActors , ABaseChar::StaticClass());
	for (AActor* OverlappingActor : OverlappingActors)
	{
		ABaseCharArray.AddUnique(Cast<ABaseChar>(OverlappingActor));
	}
	
}

// Called every frame
void AHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult)
{
	ABaseCharArray.AddUnique(Cast<ABaseChar>(OtherActor));
}

void AHole::OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex)
{
	ABaseCharArray.Remove(Cast<ABaseChar>(OtherActor));
}

void AHole::Active()
{
	for (ABaseChar* BaseChar : ABaseCharArray)
	{

		MyTimeline.SetPlayRate(0.1f);
		MyTimeline.SetLooping(false);
		//MyTimeline.SetTimelineFinishedFunc(FOnTimelineEvent::(this , &AMyActor::OnTimelineFinished));
	}
}

