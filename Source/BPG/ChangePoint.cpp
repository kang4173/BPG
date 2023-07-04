// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangePoint.h"



// Sets default values
AChangePoint::AChangePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetRelativeScale3D(FVector(3));
	Box->SetupAttachment(Scene);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Scene);
	
}

// Called when the game starts or when spawned
void AChangePoint::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &AChangePoint::OnBoxOverlapBegin);
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AChangePoint::OnMeshOverlapBegin);

	MeshLoc = Mesh->GetComponentLocation();

}

// Called every frame
void AChangePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangePoint::OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<ABaseChar>(OtherActor);

	if (Character)
	{
		Character->ChangeChar();
		Character->BaseSkill->FindPoint(MeshLoc);
	}
	
}

void AChangePoint::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

